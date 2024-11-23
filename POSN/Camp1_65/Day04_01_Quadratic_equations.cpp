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

  double a,b,c;
  cin >> a >> b >> c;

  cout << "x = ";
  coutf(2,(-b+sqrt(b*b-4*a*c))/(2*a));

  cout << "x = ";
  coutf(2,(-b-sqrt(b*b-4*a*c))/(2*a));

  return 0;
}
