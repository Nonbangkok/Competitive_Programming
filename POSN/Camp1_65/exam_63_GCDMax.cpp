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

    vector<int> A;
    int n,temp;
    cin >> n;

    while(n--){
        cin >> temp;
        A.push_back(temp);
    }
    
    temp=INT_MIN;
    forr(i,0,A.size()){
        forr(j,i+1,A.size()){
            temp=max(temp,__gcd(A[i],A[j]));
        }
    }
    cout <<temp;

  return 0;
}
