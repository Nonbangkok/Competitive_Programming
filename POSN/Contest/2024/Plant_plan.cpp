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
int visited[N][N];
int n,m,cnt;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};

void dfs(int i,int j){
    if(visited[i][j])return;
    visited[i][j]=true;
    cnt++;

    forr(k,0,4){
        int ik=i+di[k];
        int jk=j+dj[k];

        if(ik<=0||jk<=0||ik>n||jk>m||visited[ik][jk])continue;
        dfs(ik,jk);
    }
}

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)forr(j,1,m+1){
        cin >> A[i][j];
        if(A[i][j]=='#'){
            forr(k,max(0,i-2),min(i+2,n)+1)visited[k][j]=2;
            forr(k,max(0,j-2),min(j+2,m)+1)visited[i][k]=2;
            visited[max(0,i-1)][max(0,j-1)]=visited[max(0,i-1)][min(j+1,m)]=2;
            visited[min(i+1,n)][max(0,j-1)]=visited[min(i+1,n)][min(j+1,m)]=2;
        }
    }
    int mx=-1;
    forr(i,1,n+1){
        forr(j,1,m+1){
            cnt=0;
            if(visited[i][j])continue;
            dfs(i,j);
            mx=max(mx,cnt);
        }
    }

    // forr(i,1,n+1){
    //     forr(j,1,m+1){
    //         cout << visited[i][j] << sp;
    //     }
    //     cout << endll;
    // }
    cout << mx;

    return 0;
}