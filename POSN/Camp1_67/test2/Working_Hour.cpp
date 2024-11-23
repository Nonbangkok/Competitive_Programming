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

    ll res = 0;
    forr(i,0,5){
        // double a,b;
        // cin >> a >> b;
        // ll h1 = a, m1 = (a-h1)*100;
        // ll h2 = b, m2 = (b-h2)*100;

        ll h1,h2,m1,m2;
        char ch;
        cin >> h1 >> ch >> m1 >> h2 >> ch >> m2;

        // cout << a << sp << b << endll;
        // cout << h1 << sp << m1 << endll << h2 << sp << m2 << endll << endll;

        m1 += h1*60;
        m2 += h2*60;
        if(m2>m1){
            res += (m2-m1);
            // cout << (m2-m1)/60 << sp << (m2-m1)%60 << endll;
        }else{
            res += 1440-(m1-m2);
            // cout << (1440+m1-m2)/60 << sp << (1440+m1-m2)%60 << endll;
        }

    }
    cout << res/60 << sp << res%60;

    return 0;
}