#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n,m,h,s,p,a,b,c;
bool chk;
vector<pair<ll,ll>> info[1010];
vector<int> survive;

int main(){macos;

    cin >> n >> m >> h >> s >> p;
    forr(i,0,m){
        cin >> a >> b >> c;
        info[a].push_back({b,c});
    }

    forr(i,1,n+1){
        chk = true;
        for(auto [t,h]:info[i]){
            // cout << i << sp << t << sp << h << endll;
            if(t<s)continue;
            if((t-s+1)*p>h){
                chk = false;
                break;
            }
        }
        if(chk)survive.push_back(i);
    }

    cout << survive.size() << endll;
    for(int i:survive)cout << i << sp;

    return 0;
}