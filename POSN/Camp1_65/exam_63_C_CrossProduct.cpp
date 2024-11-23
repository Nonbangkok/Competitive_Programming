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

    int U[3],V[3];
    forr(i,0,3){
        cin >> U[i];
    }
    forr(i,0,3){
        cin >> V[i];
    }
    cout << U[1]*V[2]-U[2]*V[1]  << space << U[2]*V[0]-U[0]*V[2] << space << U[0]*V[1]-U[1]*V[0];

  return 0;
}
