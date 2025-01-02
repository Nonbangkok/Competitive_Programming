#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6+10;
int A[N],n,cnt,ans;

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];

    cnt = 0;
    forr(i,1,n){
        if(A[i]>=A[i-1])cnt++;
        else cnt = 0;
        ans = max(ans,cnt);
    }

    cout << (ans?ans+1:-1);

    return 0;
}