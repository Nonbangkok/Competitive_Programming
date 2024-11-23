#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int n,t,a,b,x,idx,ans=0;
    cin >> n >> t;
    int A[n];
    forr(i,0,n){
        cin >> a >> b;
        x=-(a+b*t);
        idx=upper_bound(A,A+ans,x)-A;
        if(idx==ans)ans++;
        A[idx]=x;
    }
    cout << ans;

    return 0;
}