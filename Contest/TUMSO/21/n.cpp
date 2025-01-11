#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1005;
ll a[N],b[N];

int main(){macos;

    ll n,cnt = 0;
    cin >> n;

    forr(i,0,n)cin >> a[i];
    forr(i,0,n)cin >> b[i];

    forr(i,0,n){
        ll life = 0;
        bool chk = true;
        forr(j,i,n+i){
            life += b[(j%n)]-a[(j%n)];
            if(life<0){
                chk = false;
                break;
            }
        }
        if(chk)cnt++;
    }
    cout << cnt << endll;

    return 0;
}