#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int t;
    cin >> t;

    while(t--){
        int n,mx = 0;
        cin >> n;
        int cnt[n+1];
        memset(cnt,0,sizeof(cnt));
        forr(i,0,n){
            int temp;
            cin >> temp;
            cnt[temp]++;
            mx = max(mx,cnt[temp]);
        }
        cout << n-mx << endll;
    }

    return 0;
}