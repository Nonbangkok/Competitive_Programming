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

    int n;
    cin >> n;

    forr(i,0,n){
        forr(j,0,n){
            if(i==0||j==0||j==n-1||i==n-1){
                cout << '#';
            }else{
                cout << '_';
            }
        }
        cout <<endll;
    }

    return 0;
 }
