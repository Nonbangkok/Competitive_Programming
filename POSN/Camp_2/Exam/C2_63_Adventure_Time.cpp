#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=10000;
vector<int> adj[N];
int indeg[N];
int main() {macos;

    int n,k,a,b;
    cin >> n >> k;
    forr(i,0,k){
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int> q;
    forr(i,1,n+1)if(!indeg[i])q.push(i);
    while(!q.empty()){
        int node = q.top();
        q.pop();
        cout << node << sp;

        for(auto child : adj[node]){
            indeg[child]--;
            if(!indeg[child])q.push(child);
        }
    }

    return 0;
}