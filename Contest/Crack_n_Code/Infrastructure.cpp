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
ll n,m,s,t,b,c,x,y,sum,last;
ll a[N],times[N],mx[N],mn[N],qs[N];
vector<ll> adj[N],lvl[N];
priority_queue<ll> pq;
queue<ll> q;

int main(){macos;

    cin >> n >> m >> s >> t;
    forr(i,1,n+1)cin >> a[i],times[i] = 1e18;
    forr(i,0,m){
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }

    q.push(s);
    times[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u])if(times[v]>times[u]+1)
            times[v] = times[u] + 1,q.push(v);
    }

    forr(i,1,n+1){
        lvl[times[i]].push_back(i);
    }

    forl(i,n,0){
        for(int j:lvl[i])pq.push(a[j]);
        if(!pq.empty())mx[i] = pq.top(),pq.pop();
        sum += mx[i];
    }
    
    mn[0] = 1e18;
    forr(i,1,n+1)mn[i] = min(mn[i-1],mx[i]);
    forr(i,1,n+1)if(mn[i])qs[i] = qs[i-1] + mn[i],last = i;

    forr(i,1,n+1)cout << setw(3) << mx[i] << sp;cout << endll;
    forr(i,1,n+1)cout << setw(3) << mn[i] << sp;cout << endll;
    forr(i,1,n+1)cout << setw(3) << qs[i] << sp;cout << endll;
    cout << sum << sp << last << endll << endll;

    while(t--){
        cin >> b;
        if(b==1){
            cin >> x >> y;
            // cout << sum + max(0LL,y-mn[times[x]+1]) << endll;
        }else{
            cin >> y;
            forr(i,1,n+1)cout << mn[times[i]+1] << sp;cout << endll;
            cout << endll;
            ll m = lower_bound()
        }
    }

    // not finished

    return 0;
}