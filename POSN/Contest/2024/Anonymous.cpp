#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e8+2;
bitset<int(2e8+10)> table;
int main(){macos;

    vector<int> prime;
    prime.emplace_back(0);
    prime.emplace_back(2);
    for(ll i=3;i<=N;i+=2)if(!table[i]){prime.emplace_back(i);for(ll j=i*i;j<=N;j+=i*2)table[j]=true;}

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        auto it=lower_bound(prime.begin(),prime.end(),n)-prime.begin();
        if(prime[it]==n)cout << it << endll;
        else cout << prime[it-1] << endll;
    }

    return 0;
}