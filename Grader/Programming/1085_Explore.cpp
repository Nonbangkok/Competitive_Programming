#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e5+10;
vector<int> adj[N];
bool rock[N],dp[N];
int n,m,k,a,b;

int main(){macos;

    cin >> n >> m >> k;
    forr(i,0,m){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    forr(i,0,k){
        cin >> a;
        rock[a] = true;
    }

    dp[1] = true;
    forr(i,1,n+1){
        if(!dp[i])continue;
        if(!rock[i])dp[i+1] |= dp[i];
        for(int j:adj[i])dp[j] |= dp[i];
    }

    if(dp[n])cout << 1;
    else{
        cout << 0 << sp;
        forl(i,n-1,0){
            if(dp[i]){
                cout << i;
                break;
            }
        }
    }

    return 0;
}