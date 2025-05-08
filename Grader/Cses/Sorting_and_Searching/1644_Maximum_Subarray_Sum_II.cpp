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
ll n,a,b,x,mx = -1e18;
ll qs[N];
deque<ll> dq;
 
int main(){macos;
 
    cin >> n >> a >> b;
    forr(i,1,n+1)cin >> qs[i],qs[i] += qs[i-1];
    forr(i,a,n+1){
        while(!dq.empty()&&dq.front()<i-b)dq.pop_front();
        while(!dq.empty()&&qs[dq.back()]>=qs[i-a])dq.pop_back();
        dq.push_back(i-a);
        mx = max(mx,qs[i]-qs[dq.front()]);
    }
 
    cout << mx;
 
    return 0;
}