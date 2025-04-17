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

const int N = 1e5 + 10;
const int M = 1e9 + 7;
ll n,x,cnt;
ordered_multiset<pair<ll,ll>> s;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> x;
        // cnt += s.size() - s.order_of_key({x,0}); // a[i]>=a[j]
        cnt += s.size() - s.order_of_key({x+1,0}); // a[i]>a[j]
        cnt %= M;
        s.insert({x,i});
    }
    cout << cnt;

    return 0;
}