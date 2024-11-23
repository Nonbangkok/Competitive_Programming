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
        int n;
        string s,t;
        int chk=false;
        cin >> n >> s >> t;

        forr(i,0,n){
            if(s[i]=='1')chk=1;
            if(t[i]=='1'&&chk==0){
                chk=2;
                break;
            }
        }
        cout << (chk==2?"NO":"YES") << endll;

    }

    return 0;
}