#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e6+10;
bool prime[N];
int main(){macos;

    prime[1] = true;
    for(ll i=2;i<N;i++){
        if(prime[i])continue;
        for(ll j=i*i;j<N;j+=i)prime[j] = true;
    }

    ll n,cnt = 0;
    cin >> n;
    for(int i=3;i+2<=n;i+=2){
        if(prime[i])continue;
        cnt += !prime[i+2];
    }
    cout << cnt;

    return 0;
}