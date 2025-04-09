#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010;
const int di[] = {0,0,-1,1};
const int dj[] = {-1,1,0,0};
char A[N][N];
bool water[N][N];
int n,m,mx;
string s;

void flow(int i, int j){
    water[i][j] = true;
    forr(k,0,4){
        int ik = i + di[k];
        int jk = j + dj[k];
        if(ik<1||ik>n||jk<1||jk>m)continue;
        if(water[ik][jk]||A[ik][jk]=='X')continue;
        flow(ik,jk);
    }
}

int dfs(int i,int j){
    int cnt = 0;
    A[i][j] = '.';
    forr(k,0,4){
        int ik = i + di[k];
        int jk = j + dj[k];
        if(ik<1||ik>n||jk<1||jk>m)continue;
        if(water[ik][jk])cnt++;
        if(A[ik][jk]=='X')cnt += dfs(ik,jk);
    }
    return cnt;
}

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1){
        cin >> s;
        forr(j,1,m+1)A[i][j] = s[j-1];
    }

    flow(1,1);

    forr(i,1,n+1)forr(j,1,m+1)if(A[i][j]=='X')mx = max(mx,dfs(i,j));

    cout << mx;

    return 0;
}