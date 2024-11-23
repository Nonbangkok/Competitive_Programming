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
        string s;
        cin >> s;
        bool chk = false;
        if(s.size()>=3&&s[0]=='1'&&s[1]=='0'&&s[2]!='0'&&s!="101")chk = true;
        cout << (chk?"YES":"NO") << endll;
    }

    return 0;
}