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

    int n,m;
    cin >> n >> m;
    int A[n+1];
    forr(i,0,n)A[i]=1;

    int cnt=1,p=0,k=n;
    while(k){
        p++;
        if(p==n)p=0;
        if(A[p])cnt++;
        if(cnt==m){
            cout << p+1 << sp;
            A[p]=0;
            cnt=0;
            k--;
        }
    }

    return 0;
}