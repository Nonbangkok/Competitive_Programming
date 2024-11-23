#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e5+10;
ll A[N];
int main(){macos;

    int n,q;
    cin >> n >> q;

    forr(i,0,n){
        ll temp;
        cin >> temp;
        if(i!=0)A[i-1] += temp;
        if(i!=n-1)A[i+1] += temp;
        A[i] += temp;
    }

    sort(A,A+n);

    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << upper_bound(A,A+n,r)-lower_bound(A,A+n,l) << endll;
    }

    return 0;
}