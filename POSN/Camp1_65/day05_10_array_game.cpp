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
   int n,temp,sum1=0,sum2=0;
   cin >> n;

    forr(i,0,n){
    cin >> temp;
    A.push_back(temp);
   }

   forr(i,0,n){
    cin >> temp;
    B.push_back(temp);
   }

   forr(i,0,n){
    if(A[i]>B[i]){
        sum1+=2;
    }else if(A[i]<B[i]){
        sum2+=2;
    }else{
        sum1++;
        sum2++;
    }
   }

    if(sum1>sum2){
        cout << "Team 1 wins";
    }else if(sum1<sum2){
        cout << "Team 2 wins";
    }else{
        cout << "Draw";
    }
    cout << endll << sum1 << space << sum2;



    return 0;
}