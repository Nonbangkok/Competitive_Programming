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
    if(n==0){
        cout << "ZERO NUMBER";
    }else if(n>0){
        cout << "POSITIVE NUMBER";
    }else{
        cout << "NEGATIVE NUMBER";
    }

  return 0;
}
