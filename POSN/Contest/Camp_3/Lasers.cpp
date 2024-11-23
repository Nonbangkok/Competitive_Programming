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

    ll L,R,x;
    cin >> L >> R;
    vector<vector<ll>> qs(R+1);
    vector<pair<ll,ll>> A;
    vector<ll> sz(R+1);
    forr(i,1,R+1){
        cin >> sz[i];
        qs[i].resize(sz[i]+1,0);
        forr(j,1,sz[i]+1){
            cin >> x;
            qs[i][j]=qs[i][j-1]+x;
        }
    }

    forr(i,1,R+1){
        forr(j,1,sz[i]+1){
            int wall=qs[i][j]-qs[i][j-1];
            int l=qs[i][j-1]+1;
            int r=L-(qs[i][sz[i]]-qs[i][j]);
            
            if(l+wall-1<r-wall+1)continue;

            A.push_back({r-wall+1,1});
            A.push_back({l+wall,-1});
        }
    }

    sort(A.begin(),A.end());

    ll sum=0,last=-1,ans=0;
    for(auto [pos,t]:A){
        sum+=t;
        if(last==-1)last=pos;
        if(!sum)ans+=pos-last,last=-1;
    }
    cout << ans;

    return 0;
}