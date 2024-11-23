#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m;
char A[30][30];
bool visited[30][30];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};

int main(){macos;

    queue<pair<int,int>> h,q;
    cin >> n >> m;
    forr(i,0,n)forr(j,0,m){
        cin >> A[i][j];
        if(A[i][j]=='H')h.push({i,j});
        else if(A[i][j]=='C')q.push({i,j});
    }

    int cnt=0;
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();

        if(A[i][j]=='H'){
            while(!h.empty()){
                auto [x,y]=h.front();
                if(x!=i||y!=j)q.push({x,y});
                h.pop();
            }
        }
        if(A[i][j]=='*')cnt++;

        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<0||jk<0||ik>=n||jk>=m)continue;
            if(visited[ik][jk]||A[ik][jk]=='#')continue;
            q.push({ik,jk});
            visited[ik][jk]=true;
        }
    }
    cout << cnt;

    return 0;
}