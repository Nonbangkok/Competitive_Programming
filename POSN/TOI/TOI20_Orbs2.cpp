#include <bits/stdc++.h>
#include<bits/extc++.h>
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

int main(){macos;
    int n,q,l,r,idx = 0;
    cin >> n >> q >> l >> r;
    l--,r--;
    ordered_multiset<pair<int,int>> t;
    while(n--){
        int x;
        cin >> x;
        t.insert({x,idx++});
    }
    while(q--){
        auto itl=t.find_by_order(l);
        auto itr=t.find_by_order(r);
        int x=itl->first,y=itr->first;
        t.erase(itl);
        t.erase(itr);
        t.insert({y-x,idx++});
        t.insert({(x+y)/2,idx++});
    }
    for(auto x:t)cout << x.first << " ";
}