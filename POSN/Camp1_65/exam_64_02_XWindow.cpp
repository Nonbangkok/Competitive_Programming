/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {

    int n;
    cin >> n;

    forr(i,0,n){
        forr(j,0,n){
            if(j==0||j==n-1||i==0||i==n-1||i==j||i+j==n-1){
                cout << '*';
            }else{
                cout << '-';
            }
        }
        cout << endll;
    }

  return 0;
}
