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

    const int m=1e9+7;
    vector<ll> A;
    int t,n;
    cin >> t;

    A.push_back(2);
    forr(i,1,1e6){
        A.push_back((A[i-1]*2)%m);
    }

    while(t--){
        cin >> n;
        cout << A[n-1] <<endll;
    }

    return 0;
 }
