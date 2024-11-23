#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int N=0,n=0;
    string s;
    cin >> s;

    forr(i,0,s.size()){
        if(s[i]>='A'&&s[i]<='Z')N++;
        else n++;
    }
    if(n>=N){
        forr(i,0,s.size()){
            cout << (char)tolower(s[i]);
        }
    }else{
        forr(i,0,s.size()){
            cout << (char)toupper(s[i]);
        }
    }

    return 0;
 }
