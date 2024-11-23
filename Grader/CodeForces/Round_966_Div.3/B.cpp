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
        int n,tmp;
        bool chk = true;
        cin >> n;
        bool vis[n+1];
        forr(i,1,n+1)vis[i] = false;
        forr(i,1,n+1){
            cin >> tmp;
            if(i==1)vis[tmp] = true;
            else{
                if(tmp==1){
                    if(!vis[tmp+1])chk = false;
                    vis[tmp] = true;
                }else if(tmp==n){
                    if(!vis[tmp-1])chk = false;
                    vis[tmp] = true;
                }else{
                    if(!vis[tmp-1]&&!vis[tmp+1])chk = false;
                    vis[tmp] = true;
                }
            }
            // forr(i,1,n+1)cout << vis[i] << sp;cout << endll;
        }
        cout << (chk?"YES":"NO") << endll;
    }

    return 0;
}