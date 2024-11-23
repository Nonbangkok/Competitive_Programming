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

    int n;
    double sum;
    cin >> n;
    int A[n][n];

    forr(i,0,n){
        forr(j,0,n-i-1){
            cout << space;
        }
        forr(j,0,i+1){
            if(i==j || j==0){
                cout << "1 ";
                A[i][j]=1;
            }else{
                cout << A[i-1][j-1]+A[i-1][j] << space;
                A[i][j]=A[i-1][j-1]+A[i-1][j];
            }
        }
        cout << endll;
    }

    return 0;
}