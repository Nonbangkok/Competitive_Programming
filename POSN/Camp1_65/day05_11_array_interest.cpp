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
   int n,temp,in;
   cin >> n;

   while(n--){
    cin >> temp;
    A.push_back(temp);
   }
    cin >> in;
    cout << in << endll;

   forr(i,0,A.size()){
    if(in==A[i]){
        cout << i+1 << space ;
    }
   }

    return 0;
}
