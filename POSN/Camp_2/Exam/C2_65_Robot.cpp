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
    int ix,jx,sum;
};

const int N=101,K=501;
int A[N][N],n,m,k;
bool visited[N][N][K];
int di[]={0,1,1};
int dj[]={1,0,1};

int main(){macos;

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        forr(i,1,n+1){
            forr(j,1,m+1){
                cin >> A[i][j];
                forr(l,1,k+1)visited[i][j][l]=false;
            }
        }

        queue<Non> q;
        q.push({1,1,A[1][1]});
        while(!q.empty()){
            int i = q.front().ix;
            int j = q.front().jx;
            int num = q.front().sum;
            q.pop();

            forr(l,0,3){
                int ik=i+di[l];
                int jk=j+dj[l];
                if(ik<=0||jk<=0||ik>n||jk>m||num+A[ik][jk]>k) continue;
                if(visited[ik][jk][num+A[ik][jk]]) continue;
                q.push({ik,jk,num+A[ik][jk]});
                visited[ik][jk][num+A[ik][jk]]=true;
            }
        }

        int chk=1;
        forl(l,k,0){
            if(visited[n][m][l]){
                cout << l << endll;
                chk=0;
                break;
            }
        }
        if(chk)cout << -1 << endll;
    }   

    return 0;
}