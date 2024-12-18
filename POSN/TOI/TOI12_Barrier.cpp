#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (ll i = a; i < n; i++)
#define forl(i, a, n) for (ll i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 6e6+10;
ll qs[N];
ll n,w,mx,cnt,val,sz;
deque<ll> dq;

int main(){macos;

    cin >> n >> w;
    forr(i,1,n+1)cin >> qs[i],qs[i]+=qs[i-1];

    forr(i,1,n+1){
        while(!dq.empty()&&i-dq.front()>w)dq.pop_front();
        while(!dq.empty()&&qs[dq.back()]>qs[i])dq.pop_back();
        dq.push_back(i);
        val = qs[i]-qs[dq.front()];
        sz = i-dq.front();
        if(mx<val)mx = val,cnt = sz;
        else if(mx==val)cnt = min(cnt,sz);
    }

    cout << mx << endll << cnt;

    return 0;
}