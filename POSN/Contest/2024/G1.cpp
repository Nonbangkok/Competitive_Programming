#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
bool chk[10001];
int main(){macos;

    int t,n,cnt,a,b;
    cin >> t;
    
    while(t--){
        cin >> n;
        forr(i,0,10001)chk[i]=0;
        cnt=0;
        while(n--){
            cin >> a >> b;
            if(!chk[a]){cnt++;chk[a]=1;}
            if(!chk[b]){cnt++;chk[b]=1;}
        }
        cout << cnt << endll;
    }

    return 0;
}