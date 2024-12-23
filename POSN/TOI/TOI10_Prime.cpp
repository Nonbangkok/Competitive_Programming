#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 8e6;
bool prime[N];
int n,cnt = 0;

int main(){macos;

    cin >> n;

    for(ll i=2;i<N;i++){
        if(prime[i])continue;
        for(ll j=i*i;j<N;j+=i)prime[j] = true;
        cnt++;
        if(cnt == n){cout << i;break;}
    }

    return 0;
}