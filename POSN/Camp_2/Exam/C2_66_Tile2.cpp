#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 11;
ll A[N],mem[N][100001];
ll n,m,ans=1e9,a;

void solve(ll i, ll area, ll money){
    if(mem[i][area]<money)return;
    mem[i][area] = money;
    if(area==m)ans = min(ans,money);
    else if(i<n){
        forr(j,1,101){
            if(ans<money+abs(A[i]-j)*abs(A[i]-j))continue;
            solve(i+1,area-A[i]*A[i]+j*j,money+abs(A[i]-j)*abs(A[i]-j));
        }
    }
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> A[i],a += A[i]*A[i];
    forr(i,0,n+1)forr(j,0,10001)mem[i][j] = 1e9;
    solve(0,a,0);
    cout << ans;

    return 0;
}