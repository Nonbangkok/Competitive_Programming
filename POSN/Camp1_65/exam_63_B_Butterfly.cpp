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

  int n;
  cin >> n;
  n-=1;
  for(int i=-n;i<n+1;i++){
    for(int j=-n;j<n+1;j++){
      if(abs(i)<=abs(j)){
        cout << '*';
      }else{
        cout << ' ';
      }
    }
    cout << endll;
  }

  return 0;
}
