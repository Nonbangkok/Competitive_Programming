#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,mx,now;
ll a,b;
int ans[N];
vector<int> available;
vector<tuple<ll,int,int>> times;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        times.push_back({a,0,i});
        times.push_back({b,1,i});
    }

    sort(times.begin(),times.end());

    for(auto [time,t,idx]:times){
        if(t)available.push_back(ans[idx]);
        else if(now<available.size())ans[idx] = available[now++];
        else ans[idx] = ++mx;
    }

    cout << mx << endll;
    forr(i,0,n)cout << ans[i] << sp;

    return 0;
}