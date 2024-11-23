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

    int n;
    cin >> n;
    int A[n][n],source[n],sink[n];
    forr(i,0,n){
        forr(j,0,n){
            cin >> A[i][j];
            if(A[i][j]){
                sink[i]=1;
                source[j]=1;
            }
        }
    }
    forr(i,0,n)if(!source[i])cout << i+1 << sp;cout << endll;
    forr(i,0,n)if(!sink[i])cout << i+1 << sp;
    

    return 0;
}