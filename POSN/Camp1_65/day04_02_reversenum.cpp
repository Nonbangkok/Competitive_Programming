/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int sum=0;
    string s;
    cin >> s;
    cout << s << endll;

    forr(i,0,s.size()){
        sum+=(s[i]-'0')*pow(10,i);
    }
    cout << sum << endll << sum*2;

  return 0;
}
