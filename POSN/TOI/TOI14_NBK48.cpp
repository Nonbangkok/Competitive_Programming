#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,q,temp;
    cin >> n >> q;
    int qs[n];

    cin >> qs[0];
    forr(i,1,n){
        cin >> temp;
        qs[i]=qs[i-1]+temp;
    }

    forl(i,n-1,-1){
        if(qs[i]<qs[i-1])qs[i-1]=qs[i];
    }

    while(q--){
        cin >> temp;
        cout << lower_bound(qs,qs+n,temp)-qs << endll;
    }

    return 0;
}