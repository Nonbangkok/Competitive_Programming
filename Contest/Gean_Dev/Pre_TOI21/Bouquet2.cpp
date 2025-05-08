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
int n,k;
int a[N],bit[N];
ll p[N],ans;

void solve(int i){
    if(i==n+1){
        forr(j,1,n+1)ans += p[j] * bit[j];
        // ll tmp = 0;
        // forr(j,1,n+1)tmp += p[j] * bit[j];
        // cout << tmp << endll;
        // if(i==n+1){forr(j,1,n+1)cout << bit[j];cout << endll;}
    }else{
        forr(j,1,a[i]+1){
            bit[i] = j;
            solve(i+1);
        }
    }
}

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> p[i];
    forr(i,1,n+1)cin >> a[i];

    solve(1);
    cout << ans;
    
    return 0;
}