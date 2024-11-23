#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e2+10;
int A[N][N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    forr(i,0,m){
        forr(j,0,n){
            cout << A[j][i] << sp;
        }
        cout << endll;
    }

    return 0;
}