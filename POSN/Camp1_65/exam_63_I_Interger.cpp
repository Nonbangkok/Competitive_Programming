/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {

  double n;
  int t;
  cin >> t;

  while(t--){
    cin >> n;
  if(n==(int)n){
    cout << "OK" << endll;
  }else{
    cout << "NOT INTEGER" << endll;
  }
  }

  return 0;
}
