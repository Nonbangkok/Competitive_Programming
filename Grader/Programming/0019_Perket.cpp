#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 10;
int n,ans = INT_MAX;
int s[N],b[N];

void solve(int i, int x, int y, bool chk){
    if(i==n&&chk)ans = min(ans,abs(x-y));
    else if(i<n)solve(i+1,x,y,chk),solve(i+1,x*s[i],y+b[i],true);
}

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> s[i] >> b[i];
    solve(0,1,0,false);
    cout << ans;

    return 0;
}