#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=601;
const int di[]={0,0,-1,1};
const int dj[]={-1,1,0,0};
int A[N][N];
bool visited[N][N];
ll cnt;

int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    forr(i,0,n)forr(j,0,m){
        if(A[i][j]==0||visited[i][j])continue;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            auto [ix,jx]=q.front();
            q.pop();


            forr(k,0,4){
                int ik=ix+di[k];
                int jk=jx+dj[k];

                if(ik<0||jk<0||ik>=n||jk>=m||visited[ik][jk])continue;
                if(!A[ik][jk]){cnt++;continue;}
                q.push({ik,jk});
                visited[ik][jk]=true;
            }
        }
    }
    cout << cnt;

    return 0;
}