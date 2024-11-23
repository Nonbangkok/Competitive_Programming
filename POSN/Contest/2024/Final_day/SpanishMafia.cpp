#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[102];
pair<int,int> dp[102][102];//<damage,time>
ll sum=0;

pair<int,int> MCM(int l,int r){
    if(l>=r)return {0,0};
    if(dp[l][r].second)return dp[l][r];
    if(l+1==r)return {(A[l]+A[r])%100,A[l]*A[r]};
    forr(k,l,r)dp[l][r].second=min(dp[l][r].second,MCM(l,k).second*MCM(k+1,r).second);
    return dp[l][r];
}

int main() {macos;

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> A[i];
        }
        cout << MCM(0,n-1).second << endll;
        memset(dp,0,sizeof(dp));
    }
    cout << sum;

    return 0;
 }