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

    int n;
    cin >> n;
    n--;
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            if(abs(i)+abs(j)==n)cout << '*';
            else cout << ' ';
        }
        cout << endll;
    }

    return 0;
}