#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
char l_let[]={'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b'};
char r_let[]={'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
int main(){macos;

    int t;
    cin >> t;
    forr(i,0,t){
        bool l = false , r = false;
        string s;
        cin >> s;
        if(s.size()==1){
            cout << "BOTH" << endll;
            continue;
        }
        forr(j,0,s.size()){
            forr(k,0,15){
                if(s[j]==l_let[k])l = true;
            }
            forr(k,0,11){
                if(s[j]==r_let[k])r = true;
            }
        }
        if(l&&r)cout << "NONE";
        else if(l)cout << "LEFT";
        else cout << "RIGHT";
        cout << endll;
    }

    return 0;
}