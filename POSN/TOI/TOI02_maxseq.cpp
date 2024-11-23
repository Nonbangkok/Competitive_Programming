#include <iostream>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
using namespace std;
int main() {macos;

    int n,ans=0,inx,jnx,ians,jans;
    cin >> n;
    int A[n],dp[n];
    dp[0]=0;
    forr(i,1,n+1){
        cin >> A[i];
        if(A[i]>=A[i]+dp[i-1]){
            dp[i]=A[i];
            inx=i;
            jnx=i;
        }else{
            dp[i]=A[i]+dp[i-1];
            jnx=i;
        }
        if(ans<dp[i]){
            ans=dp[i];
            ians=inx;
            jans=jnx;
        }
    }
    //dp[i]=max(A[i],A[i]+dp[i-1])
    //cout << ians << sp << jans;
    if(ans<1){
        cout << "Empty sequence";
    }else{
        forr(i,ians,jans+1){
            cout << A[i] << sp;
        }
        cout << endll;
        cout << ans;
    }

    return 0;
 }