#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    ll x,y;
};

int main(){macos;

    vector<Non> A;
    ll n,a,b;
    cin >> n;
    forr(i,0,n){cin >> a >> b;A.push_back({a,b});}
    ll dis[n];
    forr(i,0,n)dis[i]=INT_MAX;

    ll idx=0,mn,ans=0,next;
    while(1){
        mn=INT_MAX,next=-1;
        dis[idx]=-1;
        forr(i,0,n){
            if(dis[i]==-1)continue;
            dis[i]=min(dis[i],abs(A[i].x-A[idx].x)+abs(A[i].y-A[idx].y));
            if(mn>dis[i]){
                mn=dis[i];
                next=i;
            }
        }
        if(next==-1)break;
        idx=next;
        ans+=mn;
        //cout << idx << sp << mn << endll;
    }
    cout << ans;

    return 0;
}