#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 4e5 + 10;
int n,a,b;
ll dp[N],c;
vector<tuple<int,int,ll>> projects;
vector<pair<int,ll>> works[N];
unordered_map<int,int> mp;
set<int> s;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a >> b >> c;
        projects.push_back({a,b,c});
        s.insert(a);
        s.insert(b);
    }

    int j = 1;
    for(int i:s)mp[i] = j++;
    for(auto [l,r,val]:projects)works[mp[l]].push_back({mp[r],val});

    forr(l,1,s.size()+1){
        dp[l] = max(dp[l],dp[l-1]);
        for(auto [r,val]:works[l])dp[r] = max(dp[r],dp[l-1] + val);
    }

    cout << dp[s.size()];

    return 0;
}