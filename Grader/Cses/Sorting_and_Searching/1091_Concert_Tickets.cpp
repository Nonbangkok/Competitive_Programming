#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,m,x;
multiset<int> s;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> x,s.insert(x);

    while(m--){
        cin >> x;
        auto it = s.upper_bound(x);
        if(it!=s.begin()){
            cout << *prev(it) << endll;
            s.erase(prev(it));
        }else cout << -1 << endll;
    }

    return 0;
}