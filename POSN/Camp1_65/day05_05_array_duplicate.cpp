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
    int t,temp,cnt=0;
    cin >> t;

    while(t--){
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(),A.end());

    forr(i,0,A.size()){
        if(A[i]==A[i+1]){
            cnt++;
        }
    }
    cout << cnt;


    return 0;
}