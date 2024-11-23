#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

pair<int,int> count(int n,string s){
    int c0=0,c1=0;
    forr(i,0,n){
        if(s[i]=='0'&&s[i-1]!='0')c0++;
        else if(s[i]=='1') c1++;
    }
    return {c0,c1};
}

int main(){macos;

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        auto [c0,c1] = count(n,s);
        cout << (c0>=c1?"NO":"YES") << endll;
    }

    return 0;
}