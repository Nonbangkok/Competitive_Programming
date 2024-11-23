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

ll Closest_Pair(vector<Point> Px, vector<Point> Py){
    int n = Px.size();
    if(n<=3){
        ll mn = LLONG_MAX;
        forr(i,0,n-1)forr(j,i+1,n){
            mn = min(mn,dis(Px[i],Px[j]));
        }
        return mn;
    }

    int mid = n >> 1;
    Point midPoint = Px[mid];

    vector<Point> Pxl (Px.begin(),Px.begin()+mid);
    vector<Point> Pxr (Px.begin()+mid,Px.end());

    vector<Point> Pyl, Pyr;

    for(auto p:Py){
        if(p.x < midPoint.x)Pyl.push_back(p);
        else Pyr.push_back(p);
    }

    ll d = min(Closest_Pair(Pxl,Pyl),Closest_Pair(Pxr,Pyr));

    n = Py.size();
    for(int i=0;i<n;i++){
        if((Py[i].x-midPoint.x)*(Py[i].x-midPoint.x)<d){
            for(int j=i+1;j<n&&(Py[j].y-Py[i].y)*(Py[j].y-Py[i].y)<d;j++){
                d = min(d, dis(Py[i], Py[j]));
            }
        }
    }

    // vector<Point> strip;
    // for(auto p : Py) {
    //     if((p.x - midPoint.x)*(p.x - midPoint.x) < d)
    //         strip.push_back(p);
    // }

    // for(int i = 0; i < strip.size(); ++i) {
    //     for(int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y)*(strip[j].y - strip[i].y) < d; ++j) {
    //         d = min(d, dis(strip[i], strip[j]));
    //     }
    // }

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

    // ll mn = LLONG_MAX;
    
    // forr(i,0,Points.size()){
    //     forr(j,0,Points.size()){
    //         ll d = dis(Points[i],Points[j]);
    //         if(d)mn = min(mn,d);
    //     }
    // }

    // cout << mn;
    
    vector<Point> Px = Points, Py = Points;

    sort(Px.begin(),Px.end(),[](const Point &a, const Point &b) { return a.x < b.x; });
    sort(Py.begin(),Py.end(),[](const Point &a, const Point &b) { return a.y < b.y; });

    cout << Closest_Pair(Px,Py);

    return 0;
}