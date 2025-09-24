#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int main(){macos;

    int n;
    cin >> n;
    
    if(n&1){
        forr(i,0,n){
            forr(j,0,n){
                if(i+j==n/2||i+j==n+n/2-1||i-j==n/2||j-i==n/2){
                    cout << "*";
                }else cout << "-";
            }
            cout << endll;
        }
    }else{
        forr(i,0,n){
            forr(j,0,n-1){
                if(i+j==n/2-1||i+j==n+n/2-2||i-j==n/2||j-i==n/2-1){
                    cout << "*";
                }else cout << "-";
            }
            cout << endll;
        }
    }

    return 0;
}