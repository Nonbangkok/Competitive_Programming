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
        ll n;
        cin >> n;

        int res = __builtin_popcountll(n)+1;

        if(res-1==1){
            cout << 1 << endll << n << endll;
            continue;
        }

        cout << res << endll;

        forr(i,0,res){
            ll cnt=0,cur=0,val=0;

            forl(l,62,-1){
                if(n&(1ll<<l)){
                    cnt++;
                    if(cnt<=i)val+=(1ll<<l);
                    else{
                        if(cur)val+=(1ll<<l);
                        cur=1-cur;
                    }
                }
            }
            cout << val << sp;
        }
        cout << endll;   
    }

    return 0;
}