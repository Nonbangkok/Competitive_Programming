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

    int n,m;
    cin >> n >> m;
    int A[n][m];

    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    forr(i,0,n){
        forr(j,0,m){
            cout << A[i][j] << space;
        }
        cout << endll;
    }

    return 0;
}