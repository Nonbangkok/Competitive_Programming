#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int ix,jx;
};

const int N=150;
int A[N][N];
int visited[N][N][2];
int n,m;
int di[]={1,-1,0,0};
int dj[]={0,0,-1,1};

void trvsal(int i,int j,int state){
    int lvl=1;
    queue<Non> q;
    q.push({i,j});
    visited[i][j][state]=1;

    while(!q.empty()){
        int cntlvl=q.size();
        lvl++;
        while(cntlvl--){
            i = q.front().ix;
            j = q.front().jx;
            q.pop();

            forr(k,0,4){
                int ik=i+di[k];
                int jk=j+dj[k];
                if(ik<0||jk<0||ik>=n||jk>=m) continue;
                if(visited[ik][jk][state]) continue;
                if(!A[ik][jk]){
                    visited[ik][jk][state]=lvl;
                    continue;
                }
                q.push({ik,jk});
                visited[ik][jk][state]=lvl;
            }
        }
    }
}

int main() {macos;

    int sti,stj,endi,endj;
    cin >> n >> m >> sti >> stj >> endi >> endj;

    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    trvsal(sti-1,stj-1,0);
    trvsal(endi-1,endj-1,1);

    // cout << endll;
    // forr(i,0,n){
    //     forr(j,0,m){
    //         cout << visited[i][j][0] << sp;
    //     }
    //     cout << endll;
    // }
    // cout << endll;
    // forr(i,0,n){
    //     forr(j,0,m){
    //         cout << visited[i][j][1] << sp;
    //     }
    //     cout << endll;
    // }

    int cntans=0,mn=INT_MAX;
    forr(i,0,n){
        forr(j,0,m){
            if(!A[i][j]&&visited[i][j][0]&&visited[i][j][1]){
                cntans++;
                mn=min(mn,visited[i][j][0]+visited[i][j][1]-1);
            }
        }
    }

    cout << cntans << endll << mn;

    return 0;
}