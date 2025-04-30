#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,k;
bool chk;
string s,tmp;

int main(){macos;

    cin >> n >> k >> s;
    int l = 1, r = 15010, m;
    while(l<r){
        m = (l+r) >> 1;
        chk = false;
        unordered_map<string,int> mp;
        forr(i,0,n-m+1){
            tmp = s.substr(i,m);
            mp[tmp]++;
            if(mp[tmp]==k)chk = true;
        }

        if(chk)l = m + 1;
        else r = m;
    }

    cout << l - 1;

    return 0;
}