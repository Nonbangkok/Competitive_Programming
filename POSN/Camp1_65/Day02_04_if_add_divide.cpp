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

    float a,b,c;

    cin >> a >> b >> c;
    if(c==0.0){
        cout << "cannot divide by zero";
    }else{
        coutf(6,(a+b)/c);
    }

  return 0;
}
