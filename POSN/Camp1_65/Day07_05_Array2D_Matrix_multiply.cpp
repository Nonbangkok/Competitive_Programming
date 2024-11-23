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

    int n,m,l,p;
    cin >> n >> m;
    int A[n][m];

    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    cin >> l >> p;
    int B[l][p];

    forr(i,0,l){
        forr(j,0,p){
            cin >> B[i][j];
        }
    }

    int sum;
    if(m==l){
        int C[n][p];
        forr(i,0,n){
            forr(j,0,p){
                sum=0;
                forr(k,0,m){
                    sum+=A[i][k]*B[k][j];
                }
                C[i][j]=sum;
            }
        }
        forr(i,0,n){
            forr(j,0,p){
                cout << C[i][j] << space;
            }
            cout << endll;
        }
    }else{
        cout << "Can not multiply";
    }

    
    return 0;
}