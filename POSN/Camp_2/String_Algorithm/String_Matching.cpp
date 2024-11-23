#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    //Naive Algo
    string s,tem;
    cin >> s >> tem;
    int chk,cnt=0;
    forr(i,0,s.size()){
        chk=1;
        forr(j,0,tem.size()){
            if(s[i+j]!=tem[j]){
                chk=0;
                break;
            }
        }
        if(chk){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
 }
