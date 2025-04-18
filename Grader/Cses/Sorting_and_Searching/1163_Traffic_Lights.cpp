#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,x,a,l;
set<int> coor;
multiset<int> s;

int main(){macos;

    cin >> x >> n;
    coor.insert(0);coor.insert(x);
    s.insert(x);
    forr(i,0,n){
        cin >> a;
        auto it = coor.upper_bound(a);
        s.insert(*it-a);s.insert(a-*prev(it));
        s.erase(s.find(*it-*prev(it)));
        coor.insert(a);
        cout << *prev(s.end()) << sp;
    }

    return 0;
}