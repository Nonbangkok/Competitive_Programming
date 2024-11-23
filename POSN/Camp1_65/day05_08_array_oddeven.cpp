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

    vector<int> A,B;
    int t,temp;
    cin >> t;

    while(t--){
        cin >> temp;
        (temp%2==0)? A.push_back(temp): B.push_back(temp); 
    }

    if(A.size()!=0){
        forr(i,0,A.size()){
            cout << A[i] << space;
        }
    }else{
        cout << '-';
    }
    cout << endll;
    
    if(B.size()!=0){
        forr(i,0,B.size()){
            cout << B[i] << space;
        }
    }else{
        cout << '-';
    }

    return 0;
}