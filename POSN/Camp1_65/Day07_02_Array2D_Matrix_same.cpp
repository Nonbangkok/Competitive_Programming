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

    int n,m,l,i;
    cin >> n >> m;
    int A[n][m],B[n][m];;

    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    cin >> l >> i;
    if(n!=l || m!=i){
        cout << "A!=B";
        return 0;
    }

    forr(i,0,n){
        forr(j,0,m){
            cin >> B[i][j];
        }
    }


    forr(i,0,n){
        forr(j,0,m){
            cout << A[i][j] << space;
        }
        cout << endll;
    }
    cout << endll;
    forr(i,0,n){
        forr(j,0,m){
            cout << B[i][j] << space;
        }
        cout << endll;
    }


    int chk=1;
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]!=B[i][j]){
                chk=0;
            }
        }
    }

    (chk)? cout << "A==B": cout << "A!=B";
    

    return 0;
}