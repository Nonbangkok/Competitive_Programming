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
    int x,y,life;
};

const int N=101,M=501;
int A[N][N];
bool visited[N][N][M];
int di[]={0,1,1};
int dj[]={1,0,1};
int main(){macos;

    int t,n,m,k;
    cin >> t;
    
    while(t--){
        cin >> n >> m >> k;
        forr(i,0,n)forr(j,0,m){cin >> A[i][j];forr(l,0,k+1)visited[i][j][l]=false;}
        queue<Non> q;
        q.push({0,0,A[0][0]});

        while(!q.empty()){
            auto [i,j,life]=q.front();
            q.pop();

            forr(l,0,3){
                int ik=i+di[l];
                int jk=j+dj[l];

                if(ik<0||jk<0||ik>=n||jk>=m)continue;
                if(life+A[ik][jk]>k||visited[ik][jk][life+A[ik][jk]])continue;
                q.push({ik,jk,life+A[ik][jk]});
                visited[ik][jk][life+A[ik][jk]]=true;
                //cout << ik << sp << jk << sp << life+A[ik][jk] << endll;
            }
        }

        int chk=1;
        forl(i,k,-1)if(visited[n-1][m-1][i]){cout << i;chk=0;break;}
        if(chk)cout << -1;
        cout << endll;
    }

    return 0;
}