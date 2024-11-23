#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M=1e9+7;

int main() {macos;

    ll n,cnt,ans=1;
    cin >> n;
    string key,s;
    cin >> key;
    forr(i,0,n){
        cnt=0;
        forr(j,0,n){
            cin >> s;
            if(s==key)cnt++;
        }
        ans=(ans*(cnt%M))%M;
    }
    cout << ans;

    return 0;
 }