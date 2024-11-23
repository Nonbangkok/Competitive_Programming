#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int t,n;
    cin >> t;

    while(t--){
        int mx=-1;
        cin >> n;
        int A[n],dp1[n],dp2[n];
        forr(i,0,n)cin >> A[i],dp1[i]=dp2[i]=1;
        forr(i,0,n)forr(j,0,i)if(A[i]>A[j])dp1[i]=max(dp1[i],dp1[j]+1);
        forl(i,n-1,-1)forl(j,n-1,i-1)if(A[i]>A[j])dp2[i]=max(dp2[i],dp2[j]+1);
        //int w=1;for(auto i : A)cout << setw(w) << i << sp;cout << endll;for(auto i : dp1)cout << setw(w) << i << sp;cout << endll;for(auto i: dp2)cout << setw(w) << i << sp;
        forr(i,0,n)mx=max(mx,dp1[i]+dp2[i]);
        cout << mx-1 << endll;
    }

    return 0;
}