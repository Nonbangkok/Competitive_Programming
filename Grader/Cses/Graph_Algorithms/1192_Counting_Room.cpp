#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001;
bool visited[N][N];
char A[N][N];
int n,m,cnt=0;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};

void dfs(int i,int j){
    if(visited[i][j])return;
    visited[i][j]=true;

    forr(k,0,4){
        int ik=i+di[k];
        int jk=j+dj[k];

        if(ik<0||jk<0||ik>=n||jk>=m||visited[ik][jk]||A[ik][jk]=='#')continue;
        dfs(ik,jk);
    }
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    forr(i,0,n)forr(j,0,m){
        if(visited[i][j]||A[i][j]=='#')continue;
        dfs(i,j);
        cnt++;
    }
    cout << cnt;

    return 0;
}