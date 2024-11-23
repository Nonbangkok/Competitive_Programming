#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m;
    cin >> n >> m;
    int A[n],B[m];
    forr(i,0,n)A[i]=i+1;
    forr(i,0,m)cin >> B[i];
    do{
        bool chk=true;
        forr(i,0,m){
            if(A[0]==B[i]){
                chk=false;
                break;
            }
        }
        if(chk){
            forr(i,0,n){
                cout << A[i] << sp;
            }
            cout << endll;
        }
    }while(next_permutation(A,A+n));

    return 0;
 }
