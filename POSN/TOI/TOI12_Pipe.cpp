#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 15000 + 10;
int n,k,ans,curr,nxt,mn;
int dis[N];
bool vis[N];
pair<int,int> A[N];

int main() {macos;

    cin >> n >> k;
    forr(i,1,n+1){
        cin >> A[i].first >> A[i].second;
        dis[i] = 1e9;
    }
    
    curr = 1;
    forr(i,1,n+1){
        vis[curr] = 1;
        mn = 1e9;
        forr(j,1,n+1){
            if(vis[j])continue;
            dis[j] = min(dis[j],abs(A[curr].first-A[j].first)+abs(A[curr].second-A[j].second));
            if(dis[j]<mn)mn = dis[j],nxt = j;
        }
        curr = nxt;
    }
    
    sort(dis+1,dis+n+1);
    for(int i=1;i<=n-k;i++)ans += dis[i];
    cout << ans;

    return 0;
}