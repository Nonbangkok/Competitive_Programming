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

vector<ll> B;

void detobi(ll b){
    while(b){
        B.push_back(b%2);
        b/=2;
    }
}

int main() {macos;

    vector<ll> A;
    ll t,a,b,m,ans=1;
    cin >> t;

    while(t--){
        cin >> a >> b >> m;
        A.push_back(a);
        for(int i=0;pow(2,i+1)<=b;i++){
            A.push_back((A[i]*A[i])%m);
        }
        detobi(b);
        forr(i,0,A.size()){
            if(B[i]!=0){
               ans*=(A[i])%m;
                ans%=m; 
            }
        }
        cout << ans << endll;
        A.clear();
        B.clear();
        ans=1;
    }

    return 0;
}
//   1 2 4
// B 0 1 1
// A 3 9 1