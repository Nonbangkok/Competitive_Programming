#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int n,t,m,a,mx;
int income[N];
vector<int> adj[N];

int solve(int mid){
    bool visited[n];
    forr(i,0,n)visited[i] = false;
    forr(i,0,n){
        if(income[i]>mid){
            visited[i] = true;
            for(int j:adj[i])visited[j] = true;
        }
    }
    return count(visited,visited+n,false);
}

int main(){macos;

    cin >> n >> t;
    forr(i,0,n){
        cin >> income[i] >> m;
        mx = max(mx,income[i]);
        forr(j,0,m){
            cin >> a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }
    
    int l=0,r=mx,mid,cnt;
    while(l<r){
        mid = (l+r) >> 1;
        cnt = solve(mid);
        if(cnt<t)l = mid + 1;
        else r = mid;
    }
    cout << l;

    return 0;
}