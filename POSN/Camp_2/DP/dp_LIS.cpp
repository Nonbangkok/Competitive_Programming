#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;


    int t,n,A[1001],dp[1001],ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans=0;
        forr(i,0,n){
            cin >> A[i];
            dp[i]=1;
            forr(j,0,i){
                if(A[j]<A[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        cout << ans << endll;
    }

    return 0;
 }