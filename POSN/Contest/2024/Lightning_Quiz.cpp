#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=2e7+1,m=1e9+7;
bool table [N+2];
vector<ll> prime;

int main() {macos;

    prime.push_back(0);
    prime.push_back(2);
    for(ll i=3;i<N;i+=2){
        if(table[i])continue;
        prime.push_back(i);
        for(ll j=i*i;j<N;j+=i*2)table[j]=true;
    }
    // for(auto i : prime)cout << i << sp;

    int a,b;
    ll sum=0;
    cin >> a >> b;
    forr(i,a,b+1)sum=(sum+prime[i])%m;
    cout << sum;

    return 0;
}