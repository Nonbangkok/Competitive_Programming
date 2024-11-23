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

    int n,m;
    cin >> n >> m;

    forr(i,0,n){
        forr(k,0,m){
            forr(j,i+1,n)cout << ' ';
            forr(j,n-i-1,n){
                if(j==n-i-1)cout << '/';
                else cout << sp;
            }
            forr(j,n-i-1,n){
                if(j==n-1)cout << '\\';
                else cout << sp; 
            }
            forr(j,i+1,n)cout << ' ';
        }
        cout << endll;
    }

    return 0;
}