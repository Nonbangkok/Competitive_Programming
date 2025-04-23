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
using ordered_multiset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N = 2e5 + 10;
int n,k;
int a[N];
ordered_multiset<pair<int,int>> s;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1){
        cin >> a[i];
        s.insert({a[i],i});
        if(i>=k+1)s.erase(s.lower_bound({a[i-k],0}));
        if(i>=k)cout << s.find_by_order((k-1)/2)->first << sp;
    }

    return 0;
}