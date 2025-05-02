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
const int di[] = {-1,-1,-1,0,0,1,1,1};
const int dj[] = {-1,0,1,-1,1,-1,0,1};
int n,m,cnt;
int a[N][N];
bool vis[N][N];
string s;
queue<pair<int,int>> q;

void bfs(int x, int y){
    vis[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();

        forr(k,0,8){
            int ik = i + di[k];
            int jk = j + dj[k];
            if(ik<0||ik>=n||jk<0||jk>=m||vis[ik][jk]||!a[ik][jk])continue;
            vis[ik][jk] = true;
            q.push({ik,jk});
        }
    }
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,n){
        cin >> s;
        forr(j,0,m)a[i][j] = s[j] - '0';
    }
    forr(i,0,n)forr(j,0,m)if(!vis[i][j]&&a[i][j])bfs(i,j),cnt++;
    cout << cnt;

    return 0;
}