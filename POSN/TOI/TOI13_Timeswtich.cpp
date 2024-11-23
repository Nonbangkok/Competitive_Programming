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

    string pat,str;
    int n;
    cin >> n >> pat;
    n=pat.size();
    str=pat+pat;
    forr(i,1,n+1){
        if (n%i==0&&str.substr(i,n)==pat){
            cout << i;
            break;
        }
    }

    return 0;
}