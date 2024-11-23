#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6;
int A[N];
int main() {macos;

    int n,ans,x;
    cin >> n;
    ans=0;
    forr(i,0,n){
        cin >> x;
        int idx=upper_bound(A,A+ans,x)-A;
        if(ans==idx)ans++;
        A[idx]=x;
    }
    cout << ans;

    return 0;
}