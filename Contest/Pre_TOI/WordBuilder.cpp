#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e5+10;
vector<int> adj[N],dis(N,INT_MAX);
priority_queue<int,vector<int>,greater<int>> best[26];
queue<int> q;
int main(){macos;

    string ch,goal;
    int n,m,k,a,b;
    cin >> n >> m >> k >> ch;
    forr(i,0,m){
        cin >> a >> b;a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    q.push(dis[0]=0);
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(auto v:adj[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    forr(i,0,n)best[ch[i]-'A'].push(dis[i]);

    ll ans=0;
    cin >> goal;
    forr(i,0,k){
        if(best[goal[i]-'A'].empty()){
            cout << -1;
            return 0;
        }
        ans+=best[goal[i]-'A'].top();
        best[goal[i]-'A'].pop();
    }
    cout << (ans<<1);

    return 0;
}