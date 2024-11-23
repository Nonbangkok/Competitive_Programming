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

    int n;
    cin >> n;
    int A[n+1];
    A[0]=0;
    forr(i,1,n+1)cin >> A[i];
    forr(i,2,n+1)A[i]+=A[i-1];
    
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << A[b+1]-A[a] << endll;
    }

    return 0;
}