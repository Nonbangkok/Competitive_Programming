#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int chk[1000];
int mn,cnt;

int main(){macos;

    string s,pat;
    getline(cin,s);
    getline(cin,pat);
    
    int n = s.size(), m = pat.size();
    mn = 1e9;

    forr(i,0,m)chk[pat[i]] = 1,cnt++;

    forr(l,0,n){
        int tmp = cnt;
        if(chk[s[l]]==0)continue;
        for(int r=l;r<n;r++){
            if(chk[s[r]]==1){
                chk[s[r]] = 2;
                tmp--;
            }
            if(tmp==0){
                mn = min(mn,r-l+1);
                break;
            }
        }
        forr(i,0,1001)if(chk[i]==2)chk[i] = 1;
    }

    if(mn==1e9)cout << -1;
    else cout << mn;

    return 0;
}