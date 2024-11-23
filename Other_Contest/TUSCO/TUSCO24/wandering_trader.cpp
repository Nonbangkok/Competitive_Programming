#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N =1e5+10;
int A[N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> A[i];

    int last = 1;
    forr(i,2,n+1){
        if(i==n){
            cout << i-last+1 << sp;
            // cout << last << sp << i << endll;
        }else if(A[i-1]>A[i]&&A[i]<A[i+1]){
            cout << i-last+1 << sp;
            // cout << last << sp << i << endll;
            last = i;
        }
    }

    return 0;
}