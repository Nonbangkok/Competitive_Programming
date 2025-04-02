#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
ll n,m,q,a,b,k;
ll X[N],Y[N],S[N],T[N];

int main(){macos;

    cin >> n >> m >> q;
    forr(i,1,n+1)cin >> X[i];
    forr(i,1,n+1)cin >> S[i],S[i] += S[i-1];
    forr(i,1,m+1)cin >> Y[i];
    forr(i,1,m+1)cin >> T[i],T[i] += T[i-1];

    while(q--){
        cin >> a >> b >> k;
        ll l = -1e9 - 10, r = 1e9 + 10, mid;
        while(l<r){
            mid = (l+r) >> 1;
            int ix = upper_bound(X+1,X+n+1,mid)-X-1;
            int iy = upper_bound(Y+1,Y+m+1,(mid-b)/a)-Y-1;
            if(S[ix]+T[iy]<k)l = mid +1;
            else r = mid;
        }
        cout << l << endll;
    }

    return 0;
}