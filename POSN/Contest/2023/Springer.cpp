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

    vector<ll> A,B;
    ll n,m;
    cin >> n >> m;
    forr(i,0,m){
        ll temp;
        cin >> temp;
        A.push_back(temp-1);
    }

    B.push_back(A[0]);
    forr(i,1,m)B.push_back((A[i]-A[i-1])/2);
    B.push_back(n-A[m-1]-1);

    sort(B.begin(),B.end());
    cout << B[B.size()-1];

    return 0;
}