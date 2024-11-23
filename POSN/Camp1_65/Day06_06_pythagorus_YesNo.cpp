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

    int A[3];
    int t;
    cin >> t;

    while(t--){
        cin >> A[0]>> A[1] >> A[2];
        sort(A,A+3);
        (A[0]*A[0]+A[1]*A[1]==A[2]*A[2])? cout << "YES" << endll: cout << "NO" << endll;
    }

    return 0;
}