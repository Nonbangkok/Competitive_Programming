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
    int x,y;
    ll w;

    bool operator < (const Non &rhs)const{
        return w>rhs.w;
    }
};

const int N = 1010;
const int di[] = {0,0,-1,1};
const int dj[] = {-1,1,0,0};
int n,m,x,y;
ll dis[N][N],a[N][N],mn=1e18;
priority_queue<Non> q;

int main(){macos;

    cin >> n >> m >> x >> y;
    forr(i,1,n+1)forr(j,1,m+1)cin >> a[i][j],dis[i][j] = 1e18;

    q.push({x,y,dis[x][y]=a[x][y]});
    while(!q.empty()){
        auto [i,j,w] = q.top();
        q.pop();
        if(dis[i][j]<w)continue;
        if((i==1||i==n)&&(j==1||j==m))mn = min(mn,dis[i][j]);
        forr(k,0,4){
            int ik = i + di[k];
            int jk = j + dj[k];

            if(ik<=0||ik>n||jk<=0||jk>m)continue;
            if(dis[ik][jk]<=dis[i][j]+a[ik][jk])continue;
            q.push({ik,jk,dis[ik][jk]=dis[i][j]+a[ik][jk]});
        }
    }
    
    forr(i,1,n+1){
        forr(j,1,m+1)cout << dis[i][j] + mn - a[x][y] << sp;
        cout << endll;
    }

    return 0;
}