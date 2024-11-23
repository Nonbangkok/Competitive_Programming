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

    int n,mx=0;
    cin >> n;
    int A[n];
    forr(i,0,n){
        cin >> A[i];
        mx=max(mx,A[i]);
    }

    forr(i,0,mx){
        forr(j,0,n){
            if(A[j]+i>=mx){
                forr(k,j,A[j]-1)cout << '+';
            }else{
                forr(k,0,A[j]*2)cout << sp;
            }
        }
        cout << endll;
    }

    return 0;
}