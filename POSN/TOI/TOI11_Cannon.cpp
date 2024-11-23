#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+1;
int A[N];
int main() {macos;

    int n,m,k,len,x,temp;
    cin >> n >> m >> k >> len;
    forr(i,0,n)cin >> A[i];

    forr(i,0,k){
        int ans=0;
        auto l=A,r=A;
        forr(j,0,m){
            cin >> temp;
            l=lower_bound(r,A+n,temp-len);
            r=upper_bound(A,A+n,temp+len);
            ans+=r-l;
        }
        cout << ans << endll;
    }

    return 0;
}