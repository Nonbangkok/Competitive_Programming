#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    string s;
    cin >> s;
    int cnt=1,mx=1;

    forr(i,1,s.size()){
        if(s[i]==s[i-1])cnt++;
        else cnt=1;
        mx=max(mx,cnt);
    }
    cout << mx;

    return 0;
}