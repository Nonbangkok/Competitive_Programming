/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int A[480],t,a,b,sum=0;
    memset(A,0,sizeof(A));
    cin >> t;

    while(t--){
        cin >> a >> b;
        forr(i,a,b+1){
            A[i]=1;
        }
    }
    forr(i,0,480){
        sum+=A[i];
    }
    cout << 480-sum;

    return 0;
}