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

    int t,a,b,c,mx=INT_MIN;
    cin >> t;
    bool A[50000][70];
    
    forr(i,0,50000){
        forr(j,0,70){
            A[i][j]=0;
        }
    }

    while(t--){
        cin >> a >> b >> c;
        forr(i,b-1,b+c-1){
            A[a-1][i]=true;
        }
        mx=max(mx,a);
    }

    forr(i,0,mx){
        forr(j,0,70){
            if(A[i][j]) cout << 'x';
            else cout << 'o';
        }
        cout << endll;
    }

    return 0;
}