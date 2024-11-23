#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
using namespace std;
    int A[4];
int main(){

    int m,n,x,y;
    cin >> m >> n;
    int A[m][n];

    forr(i,0,m){
        forr(j,0,n){
            cin >> A[i][j];
        }
    }
    cin >> x >> y;
    int B[x][y];
    forr(i,0,x){
        forr(j,0,y){
            cin >> B[i][j];
        }
    }

    if(n!=x){
        cout << "Can not multiply";
    }else{
        int C[m][y];
        memset(C,0,sizeof(C));
        forr(i,0,m){
            forr(j,0,y){
                forr(k,0,n){
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        forr(i,0,m){
            forr(j,0,y){
                cout << C[i][j] << sp;
            }
            cout << endll;
        }
    }



    return 0;
}
//3 2 10 8 2 4 5 6 2 2 7 1 3 9