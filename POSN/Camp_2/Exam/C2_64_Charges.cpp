#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2 * 1e5 + 10;
int n,q,a,b;
int p[N];
char cmd;

int fp(int x){
    if(p[x]!=x)p[x] = fp(p[x]);
    return p[x];
}

void dsu(int a, int b){
    a = fp(a),b = fp(b);
    if(a==b)return;
    p[b] = a;
}

int main(){macos;

    cin >> n >> q;
    forr(i,1,n*2+1)p[i] = i;
    while(q--){
        cin >> cmd >> a >> b;
        if(cmd=='A')dsu(a,b+n),dsu(a+n,b);
        else if(cmd=='R')dsu(a,b),dsu(a+n,b+n);
        else if(fp(a)==fp(b+n))cout << 'A' << endll;
        else if(fp(a)==fp(b))cout << 'R' << endll;
        else cout << '?' << endll;
    }

    return 0;
}