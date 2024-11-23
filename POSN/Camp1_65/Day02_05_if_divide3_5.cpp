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

    int a;
    cin >> a;

    if(a%3==0&&a%5==0){
        cout << "3 5";
    }else if(a%3==0){
        cout << 3;
    }else if(a%5==0){
        cout << 5;
    }else{
        cout << a;
    }

  return 0;
}
