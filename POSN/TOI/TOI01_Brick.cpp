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
    char A[21][21];
    cin >> n >> m;
    int num[m];
    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    forr(i,0,m)cin >> num[i];

    forr(j,0,m){
        int st;
        forr(i,0,n){
            if(i==n-1&&A[i][j]=='.'){
                st=n-1;
            }else if(A[i][j]=='O'){
                st=i-1;
                break;
            }
        }
        if(st==-1)continue;

        forr(k,0,num[j]){
            if(st-k>=0){
                A[st-k][j]='#';
            }
        }
    }

    forr(i,0,n){
        forr(j,0,m){
            cout << A[i][j];
        }
        cout << endll;
    }

    return 0;
}