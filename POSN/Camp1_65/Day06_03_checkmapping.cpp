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
    set<int> B;
    int n,temp;
    cin >> n;

    forr(i,0,n){
        cin >> temp;
        A.push_back(temp);
        B.insert(temp);
    }

    (A.size()==B.size())? cout << "YES":cout << "NO";

    return 0;
}