#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int p[N],A[N];
int n,m,a,b;

int fp(int x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

int solve(int x, int y){
    x = fp(x),y = fp(y);
    if(x==y)return -1;
    if(A[x]<A[y]||(A[x]==A[y]&&x>y))swap(x,y);
    A[x] += A[y] >> 1;
    p[y] = x;
    return x;
}

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)cin >> A[i],p[i] = i;
    while(m--){
        cin >> a >> b;
        cout << solve(a,b) << endll;
    }

    return 0;
}