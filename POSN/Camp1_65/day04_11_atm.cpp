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

    int n,m1=0,m5=0,m10=0;
    cin >> n;

    m10=n/1000;
    n-=m10*1000;
    m5=n/500;
    n-=m5*500;
    m1=n/100;


    (m1!=0)? cout << "100 : " << m1 << endll : cout << "";
    (m5!=0)? cout << "500 : " << m5 << endll : cout << "";
    (m10!=0)? cout << "1000 : " << m10 << endll : cout << "";
    
  return 0;
}
