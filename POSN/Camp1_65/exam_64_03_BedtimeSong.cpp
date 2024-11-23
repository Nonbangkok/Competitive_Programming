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

    int hr,mi,dline=1245,rem;
    cin >> hr >> mi;
    rem=dline-(hr*60+mi);
    if(rem<=0){
        cout << "0 0";
    }else{
        cout << rem << space << ceil((float)rem/2);
    }

  return 0;
}