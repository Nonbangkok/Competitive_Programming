#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,inx,cnt=0;
    cin >> n >> inx;
    int A[n];

    forr(i,0,n){
        cin >> A[i];
    }
    sort(A,A+n);

    forr(i,0,n){
        if(A[i]>=A[inx-1]){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
 }
