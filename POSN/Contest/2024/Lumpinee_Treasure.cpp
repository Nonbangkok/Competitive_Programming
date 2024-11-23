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
    int a,b,cntk,collect;

    bool operator < (const Non &rhs) const{
        return collect<rhs.collect;
    }
};

int A[16][16];
int dp[16][16];
int di[]={-1,0};
int dj[]={0,-1};

int main() {macos;

    int n,m,k,mx=-1;
    cin >> n >> m >> k;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    priority_queue<Non> q;
    forr(i,0,n){
        forr(j,0,m){
            forr(h,0,i+1)forr(l,0,j+1)dp[h][l]=false;
            q.push({i,j,-1,0});
            while(!q.empty()){
                int x=q.top().a;
                int y=q.top().b;
                int kl=q.top().cntk;
                int money=q.top().collect;
                q.pop();

                kl+=1;
                money+=A[x][y];
                dp[x][y]=money;
                mx=max(mx,money);

                forr(p,0,2){
                    int ik=x+di[p];
                    int jk=y+dj[p];

                    if(ik<0||jk<0||ik>=n||jk>=m)continue;
                    if(kl+1>k||money+A[ik][jk]<dp[ik][jk])continue;
                    q.push({ik,jk,kl,money});
                }
            }
            //forr(h,0,i+1){forr(l,0,j+1)cout << visited[h][l] << sp;cout << endll;}
            //cout << endll;
        }
    }
    cout << mx;

    return 0;
}