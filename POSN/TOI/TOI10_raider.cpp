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
    int ix,jx,count;
};

const int N=120;
int A[N][N];
bool visited[N][N][1010];

int di[6][2]={{0,0},{1,1},{1,1},{0,0},{-1,-1},{-1,-1}};
int dj[6][2]={{1,1},{1,-1},{0,0},{-1,-1},{0,0},{1,-1}};

int main() {macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }

    queue<Non> q;
    if(A[(n-1)/2-1][0])q.push({(n-1)/2-1,0,1});
    if(A[(n-1)/2][0])q.push({(n-1)/2,0,1});
    if(A[(n-1)/2+1][0])q.push({(n-1)/2+1,0,1});

    while(!q.empty()){
        int i=q.front().ix;
        int j=q.front().jx;
        int cnt=q.front().count;
        q.pop();

        if(i==(n-1)/2&&j==m-1){
            cout << cnt;
            break;
        }

        if(visited[i][j][cnt]) continue;
        visited[i][j][cnt]=true;

        cnt++;
        forr(k,0,6){
            int ik=i+di[k][i%2];
            int jk=j+dj[k][i%2];
            if(ik<0||jk<0||ik>=n||jk>=m) continue;
            if(!A[ik][jk]||cnt%A[ik][jk]||visited[ik][jk][cnt]) continue;
            q.push({ik,jk,cnt});
            //cout << ik << sp << jk << sp << cnt << endll;
        }
    }

    return 0;
}
// 5
// 4
// 1 1 3 8
// 0 1 1 0
// 1 6 5 7
// 1 3 2 3
// 2 5 2 0

// 5
// 5
// 1 1 1 1 8
// 0 9 1 0 7
// 1 0 1 8 7
// 1 0 1 1 7
// 1 6 1 0 6

// 5
// 4
// 1 1 1 1
// 0 0 1 0
// 0 0 1 1
// 1 0 1 1
// 1 1 1 0