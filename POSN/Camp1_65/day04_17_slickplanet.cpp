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

    int t,n,chk;
    cin >> t;

    while(t--){
        cin >> n;
        chk=1;
        if(n%2==0 || n==1){
            cout << "Impossible"<< endll;
        }else{
            for(int i=3;i*i<=n;i+=2){
                if(n%i==0){
                    chk=0;
                    break;
                }
            }
            (chk) ? cout << "Maybe" << endll :cout << "Impossible" << endll;
        }
    }


    return 0;
}
