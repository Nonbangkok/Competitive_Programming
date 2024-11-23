#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=20,M=1e9+7;
ll dp[(1<<N)][N];
vector<int> adj[N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,m){
        int a,b;
        cin >> a >> b;a--;b--;
        adj[a].push_back(b);
    }
    dp[1][0]=1;
    forr(i,0,(1<<n)){
        forr(j,0,n){
            if(!dp[i][j])continue;
            if(!(i&(1<<j))||(i&(1<<(n-1))&&i!=(1<<n)-1))continue;
            for(auto k:adj[j]){
                if((i&(1<<k)))continue;
                dp[i|(1<<k)][k]+=dp[i][j];
                dp[i|(1<<k)][k]%=M;
            }
        }
    }
    cout << dp[(1<<n)-1][n-1];

    return 0;
}