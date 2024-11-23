#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;

const int k = 1e5 + 10;
bitset<k> table;
vector<ll> prime, multiply;

ll cnt = 0;

int main() {macos;

    for(ll i=2;i<k;i++){
        if(table[i])continue;
        for(ll j=0;j<prime.size();j++){
            if(prime[j]*i>k)break;
            multiply.push_back(prime[j]*i);
        }
        prime.push_back(i);
        for(ll j=i*i;j<k;j+=i)table[j] = true;
    }

    sort(multiply.begin(),multiply.end());

    ll t,n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << multiply[lower_bound(multiply.begin(),multiply.end(),n)-multiply.begin()] << endll;
    }
	
	return 0;
}