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

  int sum,a,b;
  cin >> sum >> a >> b;
  sum+=a+b;

  if(sum>=80){cout << 'A';}
  else if(sum>=70){cout << 'B';}
  else if(sum>=60){cout << 'C';}
  else if(sum>=50){cout << 'D';}
  else{cout << "F " << 50-sum;}

  return 0;
}
