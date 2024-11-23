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
        int tmp,n,mx=0,cnt=0;
        cin >> n;
        int co[n+2];
        memset(co,0,sizeof(co));
        vector<int> a;
        forr(i,0,n)cin >> tmp,co[tmp]++;
        forl(i,n,0)if(co[i])a.push_back(co[i]);
        bool chk=1;
        for(auto i :a){
            if(i&1){
                chk=0;
                break;
            }
        }
        cout << (chk?"NO":"YES") << endll;

    }

    return 0;
}