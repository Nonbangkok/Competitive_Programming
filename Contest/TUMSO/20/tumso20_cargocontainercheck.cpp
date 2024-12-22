#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define ll int
// typedef long long ll;
using namespace std;

int alphabet(char ch){
    if(ch=='A')return 10;
    if(ch<='K')return ch-'B'+12;
    if(ch<='U')return ch-'L'+23;
    return ch-'V'+34;
}

int32_t main(){macos;

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        int res = 0;
        forr(i,0,10){
            if('A'<=s[i]&&s[i]<='Z') res += alphabet(s[i]) * (1<<i);
            else res += (s[i]-'0') * (1<<i);
        }
        if(res%11==s[10]-'0')cout << s << endll;
    }

    return 0;
}