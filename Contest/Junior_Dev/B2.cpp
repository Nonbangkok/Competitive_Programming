#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    ll n,m,q;
    string s;
    cin >> q;

    while(q--){
        cin >> n >> m;
        forr(i,0,n-1){
            cin >> s;
            ll sum = 0;
            for(char ch:s){
                sum = (sum*10+(ch-'0')) % m;
            }
            cout << sum << endll;
        }
    }

    return 0;
}