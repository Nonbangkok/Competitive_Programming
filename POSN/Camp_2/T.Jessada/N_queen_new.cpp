#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 11;
int t,n;
int A[N];
bool diag1[2*N],diag2[2*N],row[N];
bool chk;

void solve(int i){
    if(i==n+1){
        cout << '[';
        forr(i,1,n+1)cout << A[i] << sp;
        cout << ']' << sp;
        chk = false;
    }else{
        forr(j,1,n+1){
            if(row[j]||diag1[n+i-j]||diag2[i+j])continue;
            row[j] = 1;
            diag1[n+i-j] = 1;
            diag2[i+j] = 1;
            A[i] = j;
            solve(i+1);
            row[j] = 0;
            diag1[n+i-j] = 0;
            diag2[i+j] = 0;
        }
    }
}

int main(){macos;

    cin >> t;
    while(t--){
        cin >> n;
        chk = true;
        memset(diag1,0,sizeof(diag1));
        memset(diag2,0,sizeof(diag2));
        memset(row,0,sizeof(row));
        solve(1);
        if(chk)cout << -1;
        cout << endll;
    }

    return 0;
}