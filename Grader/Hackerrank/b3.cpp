#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int A[(int)1e5+1];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> A[i];
    forr(i,1,n)A[i]+=A[i-1];
    int l=0,r=n-1,chk=1,m;
    while(l<=r&&chk){
        m=(l+r)/2;
        if(A[n-1]-A[m]==A[m-1]){cout << "YES";chk=0;}
        else if(A[n-1]-A[m]>A[m-1])l=m+1;
        else r=m-1;
    }
    if(chk)cout << "NO";

    return 0;
}