#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll V[21],W[21];
ll X[21],L[21];
ll n,m,w,ans,rem;

int main(){macos;

    cin >> n >> m >> w;
    forr(i,1,n+1)cin >> X[i];
    forr(i,1,n+1)cin >> L[i];

    V[0] = 1;
    W[0] = w;

    forr(i,1,n+1){
        V[i] = X[i] * V[i-1];
        W[i] = X[i] * W[i-1] - L[i];
    }

    forl(i,n,-1){
        rem = m % V[i];
        ans += ((m-rem)/V[i])*W[i];
        m %= V[i];
    }

    cout << ans;

    return 0;
}