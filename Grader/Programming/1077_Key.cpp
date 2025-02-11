#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int Mxn = 3000 , N = 1001;
int n,m,a,b,c;
int qs[Mxn][Mxn];

int main(){macos;

    cin >> n >> m;
    forr(i,0,n){
        cin >> a >> b;
        a++,b++;
        qs[a][b]++;
    }

    forr(i,1,N+1)forr(j,1,N+1)qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];

    while(m--){
        cin >> a >> b >> c;
        a++,b++;
        cout << qs[min(1001,a+c)][min(1001,b+c)] - qs[max(0,a-c-1)][min(1001,b+c)] - qs[min(1001,a+c)][max(0,b-c-1)] + qs[max(0,a-c-1)][max(0,b-c-1)] << endll;
    }

    return 0;
}