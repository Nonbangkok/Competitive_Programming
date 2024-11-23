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
        A.push_back(temp);
        B.push_back(1);
    }

    forr(i,0,A.size()){
        forr(j,i+1,A.size()){
            if(A[i]==A[j]){
                B[i]+=B[j];
                B[j]=0;
            }
        }
    }
    
    forr(i,0,A.size()){
        if(B[i]!=0){
            cout << A[i] << space << B[i] << endll;
        }
    }


    return 0;
}