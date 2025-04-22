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
int n,k;
int a[N],dp[N];

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> a[i];

    forr(i,0,k+1)forr(j,1,n+1){
        if(i-a[j]>=0)dp[i] |= dp[i-a[j]] ^ 1;
    }

    cout << (dp[k]?"First":"Second");

    return 0;
}