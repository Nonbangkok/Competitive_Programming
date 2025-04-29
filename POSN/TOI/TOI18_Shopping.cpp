#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
int n,m,x,h;
int shop[N],chkpoint[N];

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1){
        cin >> x;
        shop[i] = shop[i-1] + (x>=0?0:-x);
        chkpoint[i] = chkpoint[i-1] + (x>=0?x:0);
    }

    while(m--){
        cin >> x >> h;
        int idx = lower_bound(shop+1,shop+1+n,h+shop[x])-shop-1;
        cout << chkpoint[idx]-chkpoint[x] << endll;
    }

    return 0;
}