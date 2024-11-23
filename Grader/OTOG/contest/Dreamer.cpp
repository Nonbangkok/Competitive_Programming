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
    getline(cin,s);

    ll sum=0;
    forr(i,0,s.size()){
        if('0'<=s[i]&&s[i]<='9')sum+=s[i]-'0';
        else if('A'<=s[i]&&s[i]<='Z')sum+=s[i]-'A';
        else if('a'<=s[i]&&s[i]<='z')sum-=s[i]-'a';
    }
    cout << sum;

    return 0;
}