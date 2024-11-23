#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=11;
int a[N][N];
int main(){macos;

    int t;
    cin >> t;
    
    while(t--){
        int n,m;
        cin >> n >> m;
        forr(i,0,n)forr(j,0,m)cin >> a[i][j];
        if(n==1&&m==1){
            cout << -1 << endll;
            continue;
        }
        forr(i,0,n){
            forr(j,0,m){
                if(a[i][j]==n*m)cout << 1 << sp;
                else cout << a[i][j]+1 << sp;
            }
            cout << endll;
        }
        
    }

    return 0;
}