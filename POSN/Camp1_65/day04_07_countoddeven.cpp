/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

   int n,odd=0,even=0;

    cin >> n;
    while(n!=0){
        if(n%2==0){
            even++;
        }else{
            odd++;
        }
        cin >> n;
    }
    cout << "Odd:"<<odd<<endll;
    cout << "Even:"<<even;
	
    return 0;
}