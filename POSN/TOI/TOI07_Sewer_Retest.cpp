#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=110;
const int di[]={0,0,-1,1};
const int dj[]={-1,1,0,0};
struct Non{int x,y,depth;};
char A[N][N];
int dis[N][N];
queue<Non> q;
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j],dis[i][j]=1e9;

    q.push({0,0,dis[0][0]=1});
    while(!q.empty()){
        auto [i,j,d]=q.front();
        q.pop();

        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];
            if(ik<0||jk<0||ik>=n||jk>=m)continue;
            if(di[k]==1&&(A[i][j]!='D'&&A[i][j]!='B'))continue;
            if(di[k]==-1&&(A[ik][jk]!='D'&&A[ik][jk]!='B'))continue;
            if(dj[k]==1&&(A[i][j]!='R'&&A[i][j]!='B'))continue;
            if(dj[k]==-1&&(A[ik][jk]!='R'&&A[ik][jk]!='B'))continue;
            if(dis[ik][jk]<d+1)continue;
            if(dis[ik][jk]==d+1){
                cout << d+1 << endll << ik+1 << sp << jk+1;
                return 0;
            }
            dis[ik][jk]=d+1;
            q.push({ik,jk,d+1});
        }
    }

    return 0;
}