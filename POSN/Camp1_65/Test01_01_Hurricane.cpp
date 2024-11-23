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

    if(n<=55){
        cout << "Depression";
    }else if(n<=103){
        cout << "Tropical Storm";
    }else if(n<=134){
        cout << "Category 1 hurricane";
    }else if(n<=155){
        cout << "Category 2 hurricane";
    }else if(n<=182){
        cout << "Category 3 hurricane";
    }else if(n<=219){
        cout << "Category 4 hurricane";
    }else{
        cout << "Category 5 hurricane";
    }

  return 0;
}
