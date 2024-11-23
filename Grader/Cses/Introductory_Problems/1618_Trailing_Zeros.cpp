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

    int n,cnt = 0;
    cin >> n;

    for(int i=1;i<=n;++i){
        ll temp = i;
        while(temp%5==0){
            cnt++;
            temp/=5;
        }
    }
    cout << cnt;

    return 0;
}