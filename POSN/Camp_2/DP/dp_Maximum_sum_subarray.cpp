#include<bits/stdc++.h>
#define forr(i,a,n) for(ll i=a;i<n;i++)
#define coutf(n,m) cout<<fixed<<setprecision(n)<<m<<endl
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define space " "
#define endll "\n" 
typedef long long ll;
using namespace std;
int main(){macos;

    int n,mx=INT_MIN;
    cin >> n;
    vector<int> A(n),dp(n);
    forr(i,0,n){
        cin >> A[i];
    }
    mx=dp[0]=A[0];
    forr(i,1,n){
        dp[i]=max(A[i],A[i]+dp[i-1]);
        mx=max(mx,dp[i]);
    }
    cout << mx;

	return 0;
}