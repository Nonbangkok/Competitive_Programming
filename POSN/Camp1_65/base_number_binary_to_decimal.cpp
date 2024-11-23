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

    ll n;
    int sum=0;
    cin >> n; 

    for(int i=0;n>0;i++){
        sum+= (n%10)*pow(2,i);
        n/=10;
    }
    cout << sum;


  return 0;
}
