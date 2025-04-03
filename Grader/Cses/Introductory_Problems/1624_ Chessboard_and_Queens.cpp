#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 9;
int n = 8;
ll cnt;
char A[N][N];
bool diag1[2*N],diag2[2*N],row[N];

void solve(int i){
    if(i==n+1)cnt++;
    else{
        forr(j,1,n+1){
            if(A[i][j]=='*')continue;
            if(row[j]||diag1[n+i-j]||diag2[i+j])continue;
            row[j] = 1;
            diag1[n+i-j] = 1;
            diag2[i+j] = 1;
            solve(i+1);
            row[j] = 0;
            diag1[n+i-j] = 0;
            diag2[i+j] = 0;
        }
    }
}

int main(){macos;

    forr(i,1,n+1)forr(j,1,n+1)cin >> A[i][j];
    solve(1);
    cout << cnt;

    return 0;
}