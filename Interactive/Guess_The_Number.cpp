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
    int l=1,r=1e6,ans=-1;

    while(l<=r){
        int m = (l+r)>>1;
        cout << m << endll;
        cout.flush();
        cin >> s;
        if(s[0]=='<')r = m-1;
        else l = m+1,ans=max(ans,m);
    }

    cout << "! " << ans;
    cout.flush();

    return 0;
}