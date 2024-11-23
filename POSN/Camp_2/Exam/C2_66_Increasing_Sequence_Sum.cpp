#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,cnt=0; 
void solve(int i,int sum){
    if(sum==n)cnt++;
    else if(sum<n)forr(j,i,n-sum+1)if(sum+j<=n)solve(j,sum+j);
}

int main(){macos;

    cin >> n;
    solve(1,0);
    cout << cnt;

    return 0;
}