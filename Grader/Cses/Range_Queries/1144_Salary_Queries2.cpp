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
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int N = 2e5 + 10;
int salary[N];
int n,m,a,b;
char cmd;
ordered_multiset s;

int main(){macos;

    cin >> n >> m;

    forr(i,0,n){
        cin >> salary[i];
        s.insert({salary[i],i});
    }

    while(m--){
        cin >> cmd >> a >> b;
        if(cmd=='!'){
            a--;
            s.erase(s.find({salary[a],a}));
            salary[a] = b;
            s.insert({b,a});
        }else{
            cout << s.order_of_key({b+1,0}) - s.order_of_key({a,0}) << endll;
        }
    }

    return 0;
}