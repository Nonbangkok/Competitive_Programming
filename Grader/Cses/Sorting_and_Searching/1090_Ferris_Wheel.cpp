#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e5+10;
ll A[N];
int main(){macos;

    ll n,m;
    cin >> n >> m;
    forr(i,0,n)cin >> A[i];
    sort(A,A+n);

    ll l = 0, r = n-1, cnt = 0;
    while(l<=r){
        // if(l>r)break;
        if((A[l]+A[r])<=m){
            l++;
            r--;
        }else{
            r--;
        }
        cnt++;
    }
    cout << cnt;

    return 0;
}