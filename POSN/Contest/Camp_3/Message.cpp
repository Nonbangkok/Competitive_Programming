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

    int t;
    cin >> t;
    while(t--){
        unordered_set<int> A;
        string s;cin >> s;
        forr(i,0,s.size()/2)A.insert(s[i]);
        if(A.size()==1)cout << "NO" << endll;
        else cout << "YES" << endll;
    }

    return 0;
}