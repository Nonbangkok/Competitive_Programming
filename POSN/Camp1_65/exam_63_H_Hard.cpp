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

    int n,temp;
    cin >> n;
    vector<int> A;

    while(n--){
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(),A.end());

    cout << 2*A[A.size()-1]+A[0];

  return 0;
}
