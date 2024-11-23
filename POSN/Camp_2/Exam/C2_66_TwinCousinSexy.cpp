#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
bitset<70000010> prime;
int cnt[3];
int main(){macos;

    ll l,r;
    cin >> l >> r;
    ll N=r+10;

    prime.set();prime[0],prime[1]=false;
    for(ll i=2;i<=N;i++)if(prime[i])for(ll j=i*i;j<=N;j+=i)prime[j]=false;
    forr(i,l,r+1){
        if(!prime[i])continue;
        if(prime[i-2]||prime[i+2])cnt[0]++;
        if(prime[i-4]||prime[i+4])cnt[1]++;
        if(prime[i-6]||prime[i+6])cnt[2]++;
    }
    for(auto i:cnt)cout << i << endll;

    return 0;
}