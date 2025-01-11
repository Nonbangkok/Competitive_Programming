#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;


const int N=205;
pair<double,double> coor[N];
double dis[N];
vector<ll> adj[N];
priority_queue<pair<double,ll>> q;


int orientation(const pair<double,double> &p1, const pair<double,double> &p2, const pair<double,double> &p3) {
    double val = (p2.second - p1.second) * (p3.first - p2.first)
               - (p2.first - p1.first) * (p3.second - p2.second);
    if (val == 0.0) return 0;           // collinear
    return (val > 0.0) ? 1 : -1;        // 1 => CCW, -1 => CW
}

bool onSegment(const pair<double,double> &p1, const pair<double,double> &p2, const pair<double,double> &p3) {
    // Check if p3 lies between p1 and p2 (inclusive),
    // assuming p1, p2, p3 are collinear
    if (min(p1.first, p2.first) <= p3.first && p3.first <= max(p1.first, p2.first) &&
        min(p1.second, p2.second) <= p3.second && p3.second <= max(p1.second, p2.second)) {
        return true;
    }
    return false;
}

bool chk(const pair<double,double> &p1, const pair<double,double> &p2,const pair<double,double> &p3, const pair<double,double> &p4) 
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, p3)) return true;
    if (o2 == 0 && onSegment(p1, p2, p4)) return true;
    if (o3 == 0 && onSegment(p3, p4, p1)) return true;
    if (o4 == 0 && onSegment(p3, p4, p2)) return true;

    // Otherwise
    return false;
}


int main(){macos;

    ll n,t;
    cin >> n >> t;

    forr(i,1,n+1)cin >> coor[i].first >> coor[i].second >> coor[i+101].first >> coor[i+101].second;
    forr(i,1,n+1)forr(j,1,n+1)forr(k,1,n+1)if(!chk(coor[i],coor[j],coor[k],coor[k+101])){
        adj[i].push_back(j);
    }
    

    while(t--){
        forr(i,0,N)dis[i] = DBL_MAX/2.0;
        cin >> coor[0].first >> coor[0].second >> coor[204].first >> coor[204].second;
        q.push({0,0});
        dis[0] = 0;
        while(!q.empty()){
            ll u = q.top().second;
            double w = q.top().first;
            q.pop();

            double temp = dis[204];
            forr(i,1,101){
                if(!chk(coor[u],coor[204],coor[i],coor[i+101])){
                    dis[204] = min(dis[204],w+sqrt((coor[u].first-coor[204].first)*(coor[u].first-coor[204].first)+(coor[u].second-coor[204].second)*(coor[u].second-coor[204].second)));
                }
            }
            if(temp!=dis[204])continue;
            
            for(auto v:adj){
                if(dis[v]>dis[u]+sqrt((coor[u].first-coor[v].first)*(coor[u].first-coor[v].first)+(coor[u].second-coor[v].second)*(coor[u].second-coor[v].second))){
                    dis[v]=dis[u]+sqrt((coor[u].first-coor[v].first)*(coor[u].first-coor[v].first)+(coor[u].second-coor[v].second)*(coor[u].second-coor[v].second));
                    q.push({dis[v],v});
                }
            }
        }
    }

    return 0;
}