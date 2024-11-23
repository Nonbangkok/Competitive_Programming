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

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int x = 0, turn = -1, round = 1;
        while(abs(x)<=n){
            x += (2 * round - 1) * turn;
            turn = -turn;
            round++;
        }
        cout << (turn==1?"Sakurako":"Kosuke") << endll;
    }

    return 0;
}