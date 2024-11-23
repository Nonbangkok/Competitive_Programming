#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e5+10;
unordered_map<ll,int> mp;
int main(){macos;

    int t,n;
    cin >> t;

    while (t--){
        cin >> n;

        ll sum = 0,a;
        int last = -1, cnt = 0;
        mp[0] = -1;

        forr(i,0,n){
            cin >> a;
            sum += a;
            if (mp.count(sum) && mp[sum] >= last){
                cnt++;
                last = i+1;
            }
            mp[sum] = i+1;
        }

        cout << cnt << endll;
    }
    return 0;
}