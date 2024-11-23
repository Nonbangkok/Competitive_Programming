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
    int n,cnt=0;
    cin >> n;

    while(n!=0){
        if(n%2==1){
            cnt++;
        }
        A.push_back(n%2);
        n/=2;
    }

    for(int i=A.size()-1;i>=0;i--){
        cout << A[i];
    }
    (cnt%2==0)? cout << '1':cout << '0';

  return 0;
}
