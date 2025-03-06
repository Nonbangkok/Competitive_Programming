#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 160;
int n,m,mn=1e9,cnt;
int src[2],des[2],dis[2][N][N],A[N][N];
int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};
queue<tuple<int,int,int>> q;

void bfs(int x, int y, int s){
    q.push({x,y,dis[s][x][y]=1});
    while(!q.empty()){
        auto [i,j,c] = q.front();
        q.pop();

        forr(k,0,4){
            int ik = i+di[k];
            int jk = j+dj[k];

            if(ik<1||ik>n||jk<1||jk>m||dis[s][ik][jk])continue;
            dis[s][ik][jk] = c + 1;
            if(!A[ik][jk])continue;
            q.push({ik,jk,c+1});
        }
    }
}

int main(){macos;

    cin >> n >> m >> src[0] >> src[1] >> des[0] >> des[1];
    forr(i,1,n+1)forr(j,1,m+1)cin >> A[i][j];

    bfs(src[0],src[1],0);
    bfs(des[0],des[1],1);

    forr(i,1,n+1)forr(j,1,m+1)if(!A[i][j]&&dis[0][i][j]&&dis[1][i][j])
        cnt++,mn = min(mn,dis[0][i][j]+dis[1][i][j]-1);

    cout << cnt << endll << mn;

    return 0;
}