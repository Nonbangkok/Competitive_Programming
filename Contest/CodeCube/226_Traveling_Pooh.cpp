#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5+10;
int sticker[N],p[N];
int n,q,s,e,a,b;

int fp(int x){
    if(x==p[x])return p[x];
    return p[x] = fp(p[x]);
}

int main(){macos;

    cin >> n >> q;
    forr(i,1,n+1)p[i] = i;
    forr(i,1,n+1){
        cin >> sticker[i];
        p[sticker[i]] = i;
    }

    while(q--){
        cin >> s >> e >> a >> b;
        if(fp(a)==fp(b)){
            cout << "ERROR" << endll;
        }else{
            if(fp(s)==fp(e))cout << "DEAD" << endll;
            else cout << "SURVIVE" << endll;
        }
    }

    return 0;
}