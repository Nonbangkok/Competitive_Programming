#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int A[100000],dp1[100000],dp2[100000];
int main() {macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> A[i];

    int mn=A[0];
    forr(i,0,n){
        dp1[i]=max(dp1[i-1],A[i]-mn);
        mn=min(mn,A[i]);
    }
    //forr(i,0,n)cout << dp1[i] << sp;cout << endll;

    int mx=A[n-1];
    forl(i,n-1,-1){
        dp2[i]=max(dp2[i+1],mx-A[i]);
        mx=max(mx,A[i]);
    }
    //forr(i,0,n)cout << dp2[i] << sp;cout << endll;

    mx=-1;
    forr(i,0,n-1)mx=max(mx,dp1[i]+dp2[i+1]);
    cout << mx;
    

    return 0;
}