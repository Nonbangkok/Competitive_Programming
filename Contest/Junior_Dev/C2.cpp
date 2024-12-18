#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N= 1e7;
bitset<N> table;
vector<ll> prime;
int main(){macos;

    ll r,st,n,num,st_idx;
    cin >> r >> st >> n;

    table[1] = true;
    prime.push_back(2);
    if(st)st_idx = prime.size()-1;
    for(ll i=3;i<=r;i+=2){
        if(table[i])continue;
        prime.push_back(i);
        if(i==st)st_idx = prime.size()-1;
        for(ll j=i*i;j<=r;j+=i*2)table[j] = true;
    }

    forr(i,0,n){
        cin >> num;
        if((!table[num]&&num&1)||num==2){
            ll idx = lower_bound(prime.begin(),prime.end(),num)-prime.begin();
            if(idx>=st_idx)cout << idx-st_idx+1 << endll;
            else cout << prime.size()-st_idx+idx+1 << endll;
        }else cout << -1 << endll;
    }

    return 0;
}