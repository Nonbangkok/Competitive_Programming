#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,x;
multiset<int> s;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> x;
        auto it = s.upper_bound(x);
        if(it!=s.end())s.erase(it);
        s.insert(x);
    }

    cout << s.size();

    return 0;
}