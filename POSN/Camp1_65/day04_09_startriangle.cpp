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
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n;
    cin >> n;

    forr(i,0,n){
        forr(j,0,i+1){
            if(j==0){
                cout << '+';
            }else{
                cout << '*';
            }
        }
        cout << endll;
    }
	
    return 0;
}