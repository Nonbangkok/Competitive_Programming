#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 410;
ll n,q,mn;
ll dis[N][N];
pair<ll,ll> A[N];
pair<ll,ll> a,b;

ll cal(pair<ll,ll> i, pair<ll,ll> j){
    return abs(i.first-j.first) + abs(i.second-j.second);
}

int main(){macos;

    cin >> n >> q;
    forr(i,0,n){
        cin >> A[i].first >> A[i].second;
        cin >> A[n+i].first >> A[n+i].second;
    }

    forr(i,0,2*n)forr(j,0,2*n)dis[i][j] = dis[j][i] = cal(A[i],A[j]);
    forr(i,0,2*n)dis[i][i] = 0;
    forr(i,0,n)dis[i][n+i] = dis[n+i][i] = 0;

    forr(k,0,2*n)forr(j,0,2*n)forr(i,0,2*n)dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);

    while(q--){
        cin >> a.first >> a.second >> b.first >> b.second;
        mn = cal(a,b);
        forr(i,0,2*n)forr(j,0,2*n)
            if(i!=j)mn = min(mn,cal(a,A[i])+dis[i][j]+cal(A[j],b));
        cout << mn << endll;
    }

    return 0;
}