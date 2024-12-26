#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e3+10;
int n,m,cnt;
int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={-1,0,1,-1,1,-1,0,1};
char A[N][N];
queue<pair<int,int>> q;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];
    
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]=='0')continue;
            cnt++;
            A[i][j]='0';
            q.push({i,j});
            while(!q.empty()){
                auto [ix,jx] = q.front();
                q.pop();

                forr(k,0,8){
                    int ik = ix+di[k];
                    int jk = jx+dj[k];

                    if(ik<0||jk<0||ik>=n||jk>=m||A[ik][jk]=='0')continue;
                    A[ik][jk]='0';
                    q.push({ik,jk});
                }
            }
        }
    }

    cout << cnt;

    return 0;
}