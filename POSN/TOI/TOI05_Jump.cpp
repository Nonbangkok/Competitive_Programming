#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=3*1e4;
int A[N];
int main() {macos;

    int n,k;
    cin >> n >> k;
    forr(i,0,n)cin >> A[i];

    int mx=-1;
    forr(i,0,n){
        int x=A[i]+k;
        int pos=upper_bound(A+i-1,A+n,x)-A-1;
        mx=max(mx,pos-i);
    }
    cout << mx;

    return 0;
}