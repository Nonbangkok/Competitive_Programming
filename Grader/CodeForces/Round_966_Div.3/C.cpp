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
        int n,m;
        string s;
        cin >> n;
        int a[n];
        forr(i,0,n)cin >> a[i];
        cin >> m;
        while(m--){
            bool chk = true;
            cin >> s;
            unordered_map<char,int> mp;
            if(n!=s.size())chk = false;
            else{
                forr(i,0,n){
                    if(mp.find(s[i])==mp.end())mp[s[i]]=a[i];
                    else if(mp[s[i]]!=a[i])chk = false;
                }
            }
            cout << (chk?"YES":"NO") << endll;
        }
    }

    return 0;
}