/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (float i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int b;
    cin >> b;

    forr(i,3,b+1){
        forr(j,4,b+1){
            if(j>=i){
                if((int)sqrt(i*i+j*j)==sqrt(i*i+j*j)){
                    cout << i << space << j << space << sqrt(i*i+j*j) << endll;
                }
            }
        }
    }

    return 0;
}