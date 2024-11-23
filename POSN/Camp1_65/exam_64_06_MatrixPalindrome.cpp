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

    int n,m,chk;
    cin >> m >> n;
    char A[n][m];
    int N[n][m];

    memset(N,0,sizeof(N));

    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }

    forr(i,0,n){
        chk=1;
        forr(j,0,m/2){
            if(A[i][j]!=A[i][m-(j+1)]){
                chk=0;
                break;
            }
        }
        if(chk){
            forr(j,0,m){
                N[i][j]++;
            }
        }
    }

    forr(i,0,m){
        chk=1;
        forr(j,0,n/2){
            if(A[j][i]!=A[n-(j+1)][i]){
                chk=0;
                break;
            }
        }
        if(chk){
            forr(j,0,n){
                N[j][i]+=2;
            }

        }
    }

    forr(i,0,n){
        forr(j,0,m){
            if(N[i][j]==0){
                cout << 'N';
            }else if(N[i][j]==1){
                cout << 'H';
            }else if(N[i][j]==2){
                cout << 'V';
            }else{
                cout << 'B';
            }
        }
        cout << endll;
    }

  return 0;
}
