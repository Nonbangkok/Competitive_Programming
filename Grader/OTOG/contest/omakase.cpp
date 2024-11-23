#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int table[30];
int main(){macos;

    int n;
    cin >> n;
    while(n--){
        bool chk = true;
        string a,b;
        cin >> a >> b;
        if(a.size()!=b.size()){
            cout << "not same" << endll;
            continue;
        }
        forr(i,0,a.size())table[a[i]-'A']++;
        forr(i,0,b.size())table[b[i]-'A']--;
        forr(i,0,26)if(table[i]){
            cout << "not same" << endll;
            chk = false;
            forr(i,0,26)table[i] = 0;
            break;
        }
        if(chk)cout << "same" << endll;
    }

    return 0;
}