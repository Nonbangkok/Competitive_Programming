#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2010;
char A[N][N];
int dis[N][N];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
int n,m,cnt,ans;
queue<pair<int,int>> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)forr(j,0,m){
        cin >> A[i][j];
        if(A[i][j]=='X'){
            q.push({i,j});
            dis[i][j] = 0;
        } else dis[i][j] = 1e9;
    }

    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();

        if(A[i][j]=='A')cnt++,ans += dis[i][j],A[i][j] = 'E';

        forr(k,0,4){
            int ik = i+di[k];
            int jk = j+dj[k];

            if(ik<0||jk<0||ik>=n||jk>=m||A[ik][jk]=='W'||dis[ik][jk]<=dis[i][j]+1)continue;
            dis[ik][jk]=dis[i][j]+1;
            q.push({ik,jk});
        }
    }

    cout << cnt << sp << ans*2;

    return 0;
}