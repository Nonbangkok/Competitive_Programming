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
int n,k,ans;
int a[N],dp[N];
vector<int> A;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> a[i];
    forr(i,2,n+1)A.push_back(a[i]-a[i-1]-1);
    ans = a[n] - a[1] + 1;
    sort(A.rbegin(),A.rend());
    forr(i,0,k-1)ans -= A[i];
    cout << ans;

    return 0;
}