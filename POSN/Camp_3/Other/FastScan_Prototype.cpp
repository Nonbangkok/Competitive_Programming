#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

void fastscan(ll &n){
    bool neg=false;
    int c=getchar();
    if(c=='-')neg=true,c=getchar();
    for(n=0;c>='0'&&c<='9';c=getchar())n=(n*10)+(c-'0');
    if(neg)n*=-1;
}

int main(){macos;

    ll n;
    fastscan(n);
    cout << n;

    return 0;
}