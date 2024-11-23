#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int table[128],A[2];

int main() {macos;

    int mx=0;
    string s;
    cin >> s;
    forr(i,0,s.size()){
        if(s[i]=="≤")mx=max(mx,++A[0]);
        if(s[i]=="≥")mx=max(mx,++A[1]);
        mx=max(mx,++table[s[i]]);
    }
    cout << mx << endll;
    //cout << "≤";

    return 0;
 }
