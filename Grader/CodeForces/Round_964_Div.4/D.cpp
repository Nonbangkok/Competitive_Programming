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
        string s,t;
        cin >> s >> t;
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                if(j>=t.size())s[i]='a';
                else s[i]=t[j],j++;
            }else if(s[i]==t[j])j++;
        }
        if(j>=t.size())cout << "YES" << endll << s << endll;
        else cout << "NO" << endll;
    }

    return 0;
}