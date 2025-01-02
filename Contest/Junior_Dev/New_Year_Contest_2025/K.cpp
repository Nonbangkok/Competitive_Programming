#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int a = 26;
int n,q;
string pat,str;

int count_pattern(){
    int cnt = 0;
    forr(i,0,str.size()-pat.size()+1)if(str.substr(i,pat.size())==pat)cnt++;
    return cnt;
}

int main(){macos;

    cin >> n >> q >> str;
    while(q--){
        cin >> pat;
        cout << count_pattern() << sp;
    }

    return 0;
}