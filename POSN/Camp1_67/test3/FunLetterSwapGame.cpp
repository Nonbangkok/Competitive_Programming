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
    for(int i=0;i<s.size();i+=2){
        if(i!=s.size()-1)swap(s[i],s[i+1]);
    }
    cout << s;

    return 0;
}