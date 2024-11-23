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

ll cal(Non a,Non b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

Non warp[402];
ll dis[402][402];

int main(){macos;

    ll n,q,a,b,c,d;
    cin >> n >> q;
    ll N=n*2;

    forr(i,0,n){
        cin >> a >> b >> c >> d;
        warp[i*2].x=a;warp[i*2].y=b;
        warp[i*2+1].x=c;warp[i*2+1].y=d;
    }

    forr(i,0,N)forr(j,0,N){
        if(i==j)dis[i][j]=0;
        else dis[i][j]=INT_MAX;
    }

    forr(i,0,n){
        dis[i*2][i*2+1]=0;
        dis[i*2+1][i*2]=0;
    }

    forr(i,0,N){
        forr(j,0,N){
            dis[i][j]=min(dis[i][j],cal(warp[i],warp[j]));
        }
    }

    forr(k,0,N)forr(j,0,N)forr(i,0,N)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    while(q--){
        Non src,des;
        cin >> src.x >> src.y >> des.x >> des.y;
        ll ans=cal(src,des);
        forr(i,0,N)forr(j,0,N)if(i!=j)ans=min(ans,cal(src,warp[i])+dis[i][j]+cal(warp[j],des));
        cout << ans << endll;
    }

    // forr(i,0,N){
    //     forr(j,0,N){
    //         cout << dis[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    return 0;
}
