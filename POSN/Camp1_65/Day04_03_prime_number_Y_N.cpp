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

    int n,chk=1;
    cin >> n;

    if(n==2){
        cout << "is prime";
    }else if(n==0||n==1||n%2==0){
        cout << "is not prime";
    }else{
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
                cout << "is not prime";
                chk=0;
                break;
            }
        }
        if(chk){
            cout << "is prime";
        }
    }

  return 0;
}
