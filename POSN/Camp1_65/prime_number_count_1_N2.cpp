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

    int n,chk,cnt=0;
    cin >> n;

    cout << "2 ";
    for(int i=3;i<=n;i+=2){
        chk=1;
        for(int j=3;j*j<=i;j+=2){
            if(i%j==0){
                chk=0;
                break;
            }
        }
        if(chk){
            cout << i << ' ';
            cnt++;
        }
    }
    cout << endll << cnt+1;

  return 0;
}
