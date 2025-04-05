#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e6 + 10;
int n,q,a,b,k;
int A[N];
multiset<int> l,m,r;

int main(){macos;

    cin >> n >> q >> a >> b;
    forr(i,1,n+1)cin >> A[i];
    sort(A+1,A+n+1);

    forr(i,1,n+1){
        if(i<=a)l.insert(A[i]);
        else if(i<=b)m.insert(A[i]);
        else r.insert(A[i]);
    }

    while(q--){
        int x = *prev(m.end()) - *prev(l.end());
        int y = (*prev(m.end()) + *prev(l.end())) >> 1;
        l.erase(prev(l.end()));m.erase(prev(m.end()));
        m.insert(x);m.insert(y);
        while(l.size()!=a)l.insert(*m.begin()),m.erase(m.begin());
    }

    for(int x:l)cout << x << sp;
    for(int x:m)cout << x << sp;
    for(int x:r)cout << x << sp;

    return 0;
}