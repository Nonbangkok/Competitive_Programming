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

    list<char> A;
    auto it = A.begin();
    string s;
    //getline(cin,s);
    cin >> s;
    forr(i,0,s.size()){
        if(s[i]=='[') it=A.begin();
        else if(s[i]==']') it=A.end();
        else A.insert(it,s[i]);
    }
    for(auto i : A)cout << i;

    return 0;
}