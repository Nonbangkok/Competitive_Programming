#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6 + 10 , M = 1e9 + 7;
int n,k,x,y;
int pre,now = 1;
ll dp[2][N],ans;
vector<int> adj[110];

int main(){macos;

    cin >> n >> k;
    forr(i,0,k){
        cin >> x;
        forr(j,0,x){
            cin >> y;
            adj[y].push_back(i);
        }
    }
    forr(i,0,n)dp[pre][i] = 1LL;
    forr(i,1,k){
        forr(j,0,n){
            dp[now][j] = 0LL;
            for(int z:adj[j])dp[now][j] += dp[pre][z],dp[now][j] %= M;
        }
        swap(pre,now);
    }
    forr(i,0,n)ans += dp[pre][i],ans %= M;
    cout << ans;

    return 0;
}