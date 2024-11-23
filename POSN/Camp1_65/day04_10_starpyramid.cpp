/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n;
    cin >> n;

    forr(i,0,n){
        forl(j,n-1-i,0){
            cout << ' ';
        }
        forr(j,0,i+1){
            cout << "* ";
        }
        cout << endll;
    }
	
    return 0;
}