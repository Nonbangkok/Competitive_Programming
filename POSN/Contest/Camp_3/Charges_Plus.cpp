#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,q,a,b,pa,pb,pan,pbn;
int p[N];
char cmd;

int fp(int x){
    if(x!=p[x])p[x] = fp(p[x]);
    return p[x];
}

int main(){macos;

    cin >> n >> q;
    forr(i,1,2*n+1)p[i] = i;
    while(q--){
        cin >> cmd >> a >> b;
        pa = fp(a),pb = fp(b),pan = fp(a+n),pbn = fp(b+n);
        if(cmd=='A'){
            if(pa==pb)cout << 'X' << endll;
            else p[pbn] = pa,p[pb] = pan;
        }else if(cmd=='R'){
            if(pa==pbn)cout << 'X' << endll;
            else p[pb] = pa,p[pbn] = pan;
        }else{
            if(fp(a)==fp(b+n))cout << 'A' << endll;
            else if(fp(a)==fp(b))cout << 'R' << endll;
            else cout << '?' << endll;
        }
    }

    return 0;
}