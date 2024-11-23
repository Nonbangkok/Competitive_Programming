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

    forr(i,0,20){
        int m,n;
        cin >> m >> n;
        if(m/2-n<0||(2*n-m/2)<0)cout << 0 << endll;
        else cout << (2*n-m/2)+1 << endll;
    }

    return 0;
}