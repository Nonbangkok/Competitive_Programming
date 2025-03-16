#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n,x,ans;
priority_queue<ll,vector<ll>,greater<ll>> q;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> x;
        if(x==0&&!q.empty())ans += q.top(),q.pop();
        else if(x!=0)q.push(x);
    }

    cout << ans;

    return 0;
}