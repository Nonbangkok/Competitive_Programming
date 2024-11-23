#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int table[101];
int main(){macos;

    int n,tmp;
    cin >> n;forr(i,0,n){cin >> tmp;table[tmp]++;}
    cin >> n;forr(i,0,n){cin >> tmp;table[tmp]++;}

    int chk=1;
    forr(i,0,101)if(table[i]==2){chk=0;cout << i << sp;}cout << endll;
    if(chk)cout << -1 << endll;

    chk=1;
    forr(i,0,101)if(table[i]==1){chk=0;cout << i << sp;}cout << endll;
    if(chk)cout << -1 << endll;
    forr(i,0,101)if(table[i])cout << i << sp;

    return 0;
}