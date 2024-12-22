#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = (1<<20);
int n,q,tmp,w;
ll A[N],dp[N];
string s;

int main(){macos;

    cin >> n >> q;
    forr(i,0,1<<n){
        cin >> s >> w;
        tmp = 0;
        reverse(s.begin(),s.end());
        forr(j,0,n)if(s[j]-'0')tmp|=(1<<j);
        A[tmp] = w;
        dp[i] = -1e9;
    }

    dp[0] = 0;

    forr(i,0,1<<n){
        forr(j,0,n){
            if(i&(1<<j))continue;
            dp[i|(1<<j)] = max(dp[i|(1<<j)],dp[i]+A[i|(1<<j)]);

            int k = j+1;
            if(j==n-1||i&(1<<k))continue;
            dp[(i|(1<<j)|(1<<k))] = max(dp[(i|(1<<j)|(1<<k))],dp[i]+A[(i|(1<<j)|(1<<k))]);
        }
    }

    while(q--){
        cin >> s;
        tmp = 0;
        reverse(s.begin(),s.end());
        forr(i,0,n)if(s[i]-'0')tmp|=(1<<i);
        cout << dp[tmp] << endll;
    }

    return 0;
}