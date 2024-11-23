#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e3+10;
ll A[N],mxl[N],mxr[N],ans;
int main(){macos;

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        ans = INT_MAX;
        forr(i,1,n+1)cin >> A[i],mxl[i]=mxr[i]=0;
        for(int i=2;i<=n;i+=2)mxl[i] = max(mxl[i-2],A[i]-A[i-1]);
        for(int i=n-1;i>=1;i-=2)mxr[i] = max(mxr[i+2],A[i+1]-A[i]);
        // for(int i=2;i<=n;i+=2)cout << mxl[i] << sp;cout << endll;
        // for(int i=2;i<=n;i+=2)cout << mxr[i] << sp;cout << endll;
        if(n%2==0)cout << mxl[n] << endll;
        else{
            A[n+1]=1e18;
            A[n+1]+=10;
            for(int i=1;i<=n;i++){
                if(i&1){
                    if(A[i]<=A[i-1]+1 and A[i]>=A[i+1]-1)continue;
                    ans = min(ans,max(mxl[i-1],mxr[i+1]));
                }
            }
            ans = max(ans,1LL);
            cout << ans << endll;
        }
    }

    return 0;
}