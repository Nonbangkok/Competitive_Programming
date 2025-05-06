#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, M = 2e3 + 1;
ll s,n,v,w,x;
// ll v[N],w[N],x[N];
ll dp[M],cnt[M];
bool vis[M];
vector<pair<ll,ll>> a[M];

int main(){macos;

    cin >> s >> n;
    forr(i,1,n+1){
        cin >> v >> w >> x;
        a[w].push_back({v,x});
    }

    for(auto &i:a){
        sort(i.rbegin(),i.rend());
        forr(j,0,i.size())swap(i[j].first,i[j].second);
        forr(j,1,i.size())i[j].first += i[j-1].first;
    }

    // for(auto &i:a){
    //     for(auto &[y,z]:i)cout << '(' << y << ',' << z << ')' << sp;
    //     cout << endll;
    // }
    // cout << endll;

    vis[0] = true;
    forr(i,1,s+1){
        if(a[i].empty())continue;
        memset(cnt,0,sizeof(cnt));
        forr(j,i,s+1){
            if(vis[i-j])continue;
            int idx =  upper_bound(a[i].begin(),a[i].end(),make_pair(cnt[j-i]+1,cnt[j-i]+1))-a[i].begin();
            if(idx>=a[i].size())continue;
            vis[i-j] = true;
            if(dp[j]<dp[j-i]+a[i][idx].second)dp[j]=dp[j-i]+a[i][idx].second,cnt[j]=cnt[j-1]+1;
            if(dp[j]==dp[j-i]+a[i][idx].second)cnt[j]=min(cnt[j],cnt[j-1]+1);
        }
    }

    // cin >> s >> n;
    // forr(i,1,n+1)cin >> v[i] >> w[i] >> x[i];
    // forr(i,1,n+1)forl(j,s,w[i]-1)forr(k,1,x[i]+1)
    //     if(j>=w[i]*k)dp[j] = max(dp[j],dp[j-w[i]*k]+v[i]*k);
    //     else break;

    cout << dp[s];

    return 0;
}