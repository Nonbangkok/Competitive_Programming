#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

//binary lifting
const int N = 2e5+10, LOG = 20;
int up[N][LOG];

int main(){macos;

    int n,q,x,k;
    cin >> n >> q;
    forr(i,2,n+1)cin >> up[i][0];
    forr(i,1,n+1)forr(j,1,LOG)up[i][j] = up[up[i][j-1]][j-1];
    while(q--){
        cin >> x >> k;
        forr(i,0,LOG)if(k&(1<<i))x = up[x][i];
        cout << (x?x:-1) << endll;
    }

    return 0;
}