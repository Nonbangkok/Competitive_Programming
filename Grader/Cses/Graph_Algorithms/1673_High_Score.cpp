#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2510;
int n,m,a,b;
ll dis[N],c;
bool visited[N];

int main(){macos;

    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    

    return 0;
}