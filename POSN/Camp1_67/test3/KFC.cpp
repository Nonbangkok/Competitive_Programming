#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e3+10;
ll A[N][N];
int main(){macos;

    int n,m,idx;
    cin >> n >> m;

    forr(i,0,m)forr(j,0,n)cin >> A[i][j];

    ll mx = INT_MIN;
    forr(i,0,n){
        ll sum = 0;
        forr(j,0,m)sum+=A[j][i];
        if(sum>mx){
            mx = sum;
            idx = i+1;
        }
    }
    cout << idx << endll << mx;

    return 0;
}