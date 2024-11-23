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

    string s,base="123456789*0#";
    char ch,a[12];
    forr(i,0,12)cin >> a[i];
    forr(i,0,10){
        cin >> ch;
        forr(i,0,12){
            if(ch!=a[i])continue;
            cout << base[i];
            break;
        }
    }

    return 0;
}