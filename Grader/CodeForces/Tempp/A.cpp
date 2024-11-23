#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

char next_letter(char ch){
    if(ch=='z')return 'a';
    else return char(ch+1);
}

int main(){macos;

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if(n==1)cout << s[0] << next_letter(s[0]);
        else{
            bool chk = true;
            forr(i,0,n){
                cout << s[i];
                if(i+1<=n-1 && s[i]==s[i+1] && chk){
                    cout << next_letter(s[i]);
                    chk = false;
                }
            }
            if(chk)cout << next_letter(s[n-1]);
        }
        cout << endll;
    }

    return 0;
}