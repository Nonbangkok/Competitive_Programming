/*
TASK: Touched
LANG: cpp
AUTHOR: Nonbangkok
CENTER: WU
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct CustomHash{
    size_t operator()(const string &s)const{
        size_t hash = 0;
        for(char c:s)hash = hash * 62 + c;
        return hash;
    }
};

int n;
string t;
unordered_set<string,CustomHash> s;

int main(){macos;

    cin >> n;
    s.reserve(n);
    
    while(n--){
        cin >> t;
        if(!s.insert(t).second){
            cout << "YES" << endll;
        }else{
            cout << "NO" << endll;
        }
    }

    return 0;
}