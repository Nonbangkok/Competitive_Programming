/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;

int A[26];

int main() {

    string s;
    int t,j,n,cnt;
    cin >> t;

    while(t--){
        cin >> j >> n >> s;
        cnt=1;
        memset(A,0,sizeof(A));
        forr(i,0,j){
            A[s[i]-'a']++;
        }
        forr(i,0,26){
            if(A[i]>n){
                cnt=0;
                break;
            }
        }
        if(cnt){
            cout << "YES" << endll;
        }else{
            cout << "NO" << endll;
        }
    }

  return 0;
}
