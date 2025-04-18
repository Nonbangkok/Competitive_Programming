#include <bits/stdc++.h>
#include <bits/extc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

using namespace __gnu_pbds;
template<class T>
using ordered_multiset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n,k,idx;
ordered_multiset<int> s;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)s.insert(i);

    idx = k % n;
    while(n--){
        auto it = s.find_by_order(idx);
        cout << *it << sp;
        s.erase(it);
        if(n)idx = (idx%n+k)%n;
    }

    return 0;
}