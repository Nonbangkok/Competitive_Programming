#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int co=1000;

char A[co][co];
int B[co][co];
int n,m;

void think (int i ,int j,int iv,int jv){
    i+=iv;
    j+=jv;
    if(!(A[i][j]=='X'||i<0||j<0||i==n||j==m)){
        B[i][j]+=1;
        think(i,j,iv,jv);
    }
}

int main() {macos;

    cin >> n >> m;

    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]=='S'){
                B[i][j]+=1;
                think(i,j,0,1);//right
                think(i,j,1,0);//down
                think(i,j,0,-1);//left
                think(i,j,-1,0);//up
            }
        }
    }

    forr(i,0,n){
        forr(j,0,m){
            cout << B[i][j] << sp;
        }
        cout << endll;
    }

    return 0;
 }
