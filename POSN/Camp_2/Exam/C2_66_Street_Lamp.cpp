#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int A[1001];
int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> A[i];
    sort(A+1,A+n+1);
    ll sum=0;
    forr(i,1,n+1){
        A[i]+=A[i-1];
        sum+=A[i];
    }
    cout << sum*2;

    return 0;
}