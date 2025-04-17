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
ll n,m,a,b,cnt = 1;
ll a[N],b[N];

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> a[i];
    forr(i,0,n)b[a[i]-1] = i + 1;
    // forr(i,0,n)cout << b[i] << sp;cout << endll;
    forr(i,0,n-1)if(b[i]>b[i+1])cnt++;
    
    while(m--){
        cin >> a >> b;
    }

    return 0;
}