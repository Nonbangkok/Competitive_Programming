#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define int long long
typedef long long ll;
using namespace std;

const int N = 2e5+10;

struct Non{
    int v,t;
    ll num;
};

struct Point{
    ll x,y;
};

vector<Non> adj[N];
vector<Point> Points;
int n,m,l;

ll dis(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void dfs(int i, ll s1, ll s2){
    if(i == n)Points.push_back({s1,s2});
    for(auto [j,t,m] : adj[i]){
        if(t == 1)dfs(j,s1+m,s2);
        else dfs(j,s1,s2+m);
    }
}

ll Closest_Pair(int l, int r){
    if(r-l+1<=3){
        ll mn = LLONG_MAX;
        forr(i,l,r)forr(j,i+1,r+1)mn = min(mn,dis(Points[i],Points[j]));
        return mn;
    }

    int mid = (l+r)>>1;
    int d = min(Closest_Pair(l,mid),Closest_Pair(mid+1,r));
    vector<Point> strip;

    for(int i=l;i<=r;i++)if((Points[i].x-Points[mid].x)*(Points[i].x-Points[mid].x)<d)strip.push_back(Points[i]);

    sort(strip.begin(),strip.end(),[](const Point &a, const Point &b) { return a.y < b.y; });

    for(int i=0;i<strip.size();i++){
        for(int j=i+1;j<strip.size() && (strip[j].y - strip[i].y)*(strip[j].y - strip[i].y) < d;j++){
            d = min(d,dis(strip[i],strip[j]));
        }
    }

    return d;
}

int32_t main(){macos;

    cin >> n >> m >> l;
    forr(i,0,l){
        int temp;
        cin >> temp;
    }
    forr(i,0,m){
        int a,b,c;
        ll d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b,c,d});
    }
    
    dfs(1,0,0);

    sort(Points.begin(),Points.end(),[](const Point &a, const Point &b) { return a.x < b.x; });

    cout << Closest_Pair(0,Points.size()-1);

    return 0;
}