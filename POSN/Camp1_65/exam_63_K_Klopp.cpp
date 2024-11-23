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
    int n,mx=-1;
    cin >> n;
    A.push_back(n);
    
    while(n!=1){
        if(n%2==0){
            n=floor(pow(n,0.5));
            A.push_back(n);
        }else{
            n=floor(pow(n,1.5));
            A.push_back(n);
        }
    }
    forr(i,0,A.size()){
        mx=max(mx,A[i]);
    }
    cout << mx << space << A.size();

  return 0;
}
