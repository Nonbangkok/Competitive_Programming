/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    vector<int> A;
    int n;

    while(1){
        cin >> n;
        if(n<0||n>9){
            break;
        }
        A.push_back(n);
    }

    forr(i,0,A.size()){
        forr(j,0,i+1){
            cout << A[j];
        }
        cout << endll;
    }

    return 0;
}
