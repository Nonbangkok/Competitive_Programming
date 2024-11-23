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
char A[N][N];
int mark[N][N];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
int main(){macos;

    int n,m,q;
    cin >> n >> m >> q;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    int color=1;
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]=='#')mark[i][j]=-1;
            else if(mark[i][j]==0){

                queue<pair<int,int>> q;
                q.push({i,j});
                mark[i][j]=color;
                while(!q.empty()){
                    auto [ix,jx]=q.front();
                    q.pop();

                    forr(k,0,4){
                        int ik=ix+di[k];
                        int jk=jx+dj[k];

                        if(ik<0||jk<0||ik>=n||jk>=m)continue;
                        if(mark[ik][jk]||A[ik][jk]=='#')continue;
                        q.push({ik,jk});
                        mark[ik][jk]=color;
                    }
                }
                color++;
            }
        }
    }
    //forr(i,0,n){forr(j,0,m)cout << mark[i][j] << sp;cout << endll;}
    
    forr(i,0,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;

        (mark[a][b]==mark[c][d]&&mark[a][b]!=-1&&mark[c][d]!=-1)?cout << "YES":cout << "NO";
        cout << endll;
    }

    return 0;
}