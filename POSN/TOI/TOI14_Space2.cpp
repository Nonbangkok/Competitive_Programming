#include <iostream>
#include <queue> //queue
#include <string.h> //string
#include <utility> //pair
#include <bitset> //bitset
#include <limits.h> //INT_MAX,INT_MIN
#define forr(i, a, n) for (ll i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=2001;
const int M=10001;
ll ans[3];
bitset<N> A[M],visited[M];
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

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

    queue<pair<ll,ll>> q;
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]&&!visited[i][j]){
                //cout << i << sp << j << endll;
                ll mni=INT_MAX,mxi=INT_MIN,mnj=INT_MAX,mxj=INT_MIN,area=0;
                q.push({i,j});
                visited[i][j]=true;

                while(!q.empty()){
                    ll ix = q.front().first;
                    ll jx = q.front().second;
                    q.pop();

                    mni=min(mni,ix);
                    mxi=max(mxi,ix);
                    mnj=min(mnj,jx);
                    mxj=max(mxj,jx);

                    area++;
                    forr(k,0,4){
                        ll ik = ix+di[k];
                        ll jk = jx+dj[k];
                        if(ik<0||jk<0||ik>=n||jk>=m||!A[ik][jk]||visited[ik][jk]) continue;
                        q.push({ik,jk});
                        visited[ik][jk]=true;
                    }
                }
                if(mxi-mni==mxj-mnj){
                    if(area%(mxi-mni+1))ans[1]++;
                    else ans[0]++;
                }else ans[2]++;
            }
        }
    }

    forr(i,0,3){
        cout << ans[i] << sp;
    }

    return 0;
}