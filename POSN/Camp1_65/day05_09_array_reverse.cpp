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
   int n,temp;
   cin >> n;

   while(n--){
    cin >> temp;
    A.push_back(temp);
   }

   forr(i,0,A.size()){
    cout << A[A.size()-i-1] << space;
   }

    return 0;
}