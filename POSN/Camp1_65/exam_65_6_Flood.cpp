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
#define forrr(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

  int n,temp,mx=-1,imx;
  cin >> n;
  vector<int> A,C(n-1);

  forr(i,0,n){
    cin >> temp;
    A.push_back(temp);
    if(mx<temp){
        mx=temp;
        imx=i;
    }
  }

    forr(i,0,imx){ 
        forr(j,i,imx){
            C[j]=max(C[j],A[i]);
        }
    }

    forrr(i,A.size()-1,imx){ 
        forrr(j,i-1,imx){
            C[j]=max(C[j],A[i]);
        }
    }

    C[imx]=min(C[imx-1],C[imx+1]);

    forr(i,0,C.size()){
        cout << C[i] << space;
    }
    cout << endll;
  

  return 0;
}