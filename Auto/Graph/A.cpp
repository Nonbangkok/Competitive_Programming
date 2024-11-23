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

    int n,sum=0;
    cin >> n;
    int A[n][n];
    forr(i,0,n){
        forr(j,0,n){
            cin >> A[i][j];
            if(A[i][j])sum++;
        }
    }
    cout << sum/2;

    return 0;
}