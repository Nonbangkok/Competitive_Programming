#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1001;
int A[N][N],ans[3];
bool visited[N][N];
int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={1,0,-1,1,-1,1,0,-1};

int main() {macos;

    string s;
    int n,m;
    cin >> m >> n;
    forr(i,0,n){
        cin >> s;
        forr(j,0,m){
            A[i][j]=s[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]&&!visited[i][j]){
                //cout << i << sp << j << endll;
                int mni=INT_MAX,mxi=INT_MIN,mnj=INT_MAX,mxj=INT_MIN;
                q.push({i,j});
                visited[i][j]=true;

                while(!q.empty()){
                    int ix = q.front().first;
                    int jx = q.front().second;
                    q.pop();

                    mni=min(mni,ix);
                    mxi=max(mxi,ix);
                    mnj=min(mnj,jx);
                    mxj=max(mxj,jx);

                    forr(k,0,8){
                        int ik = ix+di[k];
                        int jk = jx+dj[k];
                        if(ik<0||jk<0||ik>=n||jk>m||!A[ik][jk]||visited[ik][jk]) continue;
                        q.push({ik,jk});
                        visited[ik][jk]=true;
                    }
                }
                if(mxi-mni==mxj-mnj){
                    if(A[mni][mnj])ans[0]++;
                    else ans[1]++;
                }else ans[2]++;
            }
        }
    }

    forr(i,0,3){
        cout << ans[i] << sp;
    }

    return 0;
}