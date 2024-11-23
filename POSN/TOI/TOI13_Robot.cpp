#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=2001;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
char A[N][N];
int dis[N][N];

int main() {macos;

    queue<pair<int,int>> q;
    int n,m,cnt=0,ans=0;
    cin >> n >> m;
    forr(i,0,n)cin >> A[i];
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]=='X')q.push({i,j});
            else if(A[i][j]=='W')dis[i][j]=-1;
            else dis[i][j]=int(1e9);
        }
    }

    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        
        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<0||jk<0||ik>=n||jk>=m)continue;
            if(dis[ik][jk]>dis[i][j]+1){
                dis[ik][jk]=dis[i][j]+1;
                q.push({ik,jk});
            }
        }
    }

    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]=='A'&&dis[i][j]!=int(1e9)){
                ans+=dis[i][j];
                cnt++;
            }
        }
    }

    cout << cnt << sp << ans*2;

    return 0;
}