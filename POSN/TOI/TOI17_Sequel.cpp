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

    int n,q;
    cin >> n >> q;
    int A[n+1];
    ll qs[n+1];
    qs[0]=0;
    forr(i,1,n+1){
        cin >> A[i];
        if(i==1) qs[i]=A[i];
        else qs[i]=qs[i-1]+A[i];
    }

    while(q--){
        int a,b,c;
        ll sum = 0;
        cin >> a >> b >> c;
        if(b==1) cout << qs[c]-qs[a-1] << sp;
        else{
            for(int i=a;i<=c;i+=b)sum+=A[i];
            cout << sum << sp;
        }
    }

    return 0;
}