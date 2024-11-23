#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int A,B,C,n=10001,m=-10001;
    cin >> A >> B >> C;

    forr(x,m,n){
        forr(y,m,n){
                int z=A-x-y;
                if(x==y||y==z||x==z)continue;
                if(x*y*z==B&&x*x+y*y+z*z==C){cout << x << sp << y << sp << z;return 0;}
        }
    }
    cout << "No solution.";

    return 0;
}