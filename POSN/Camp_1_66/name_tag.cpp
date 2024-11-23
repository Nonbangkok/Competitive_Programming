#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std; 

int chk[26];

int main() {macos;

    int t;
    cin >> t;
    string s;
    t++;
    while(t--){
        getline(cin,s);
        forr(i,0,s.size()){
            if(s[i]!=' '){
                chk[s[i]-'A']++;
            }
        }
    }

    forr(i,0,26){
        cout << char(i+int('A')) <<'='<< chk[i] << endll;
    }

    return 0;
 }
