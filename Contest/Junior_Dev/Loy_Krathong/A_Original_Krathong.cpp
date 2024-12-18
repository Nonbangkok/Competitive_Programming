#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (long long i = a; i < n; i++)
#define forl(i, a, n) for (long long i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point{
    ld x,y;
};

const int N = 1e5 + 10;
ld A[N],B[N];
vector<Point> Points;

ld dis(const Point &a, const Point &b) {
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    return dx*dx + dy*dy;
}

ld Closest_Pair(ll l, ll r){
    if(r-l+1<=3){
        ld mn = LDBL_MAX;
        forr(i,l,r)forr(j,i+1,r+1)mn = min(mn,dis(Points[i],Points[j]));
        return mn;
    }

    ll mid = (l+r)>>1;
    ld d = min(Closest_Pair(l,mid),Closest_Pair(mid+1,r));
    vector<Point> strip;

    for(ll i=l;i<=r;i++)if((Points[i].x-Points[mid].x)*(Points[i].x-Points[mid].x)<d)strip.push_back(Points[i]);

    sort(strip.begin(),strip.end(),[](const Point &a, const Point &b) { return a.y < b.y; });

    for(ll i=0;i<strip.size();i++){
        for(ll j=i+1;j<strip.size() && (strip[j].y - strip[i].y)*(strip[j].y - strip[i].y) < d;j++){
            d = min(d,dis(strip[i],strip[j]));
        }
    }

    return d;
}

int main(){macos;

    ll n;
    cin >> n;
    forr(i,1,n+1)cin >> A[i],A[i]+=A[i-1];
    forr(i,1,n+1)cin >> B[i],B[i]+=B[i-1];

    forr(i,0,n+1)Points.push_back({A[i],B[i]});
    sort(Points.begin(),Points.end(),[](const Point &a, const Point &b) { return a.x < b.x; });

    cout << ll(Closest_Pair(0,Points.size()-1));

    return 0;
}