#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m,x,y,cnt=0;
char A[30][30];
bool visited[30][30];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
vector<pair<int,int>> h;

void trvsal(int i,int j){
    if(visited[i][j]||A[i][j]=='#')return;
    visited[i][j]=true;

    if(A[i][j]=='H')for(auto k:h)trvsal(k.first,k.second);
    if(A[i][j]=='*')cnt++;

    forr(k,0,4){
        int ik=i+di[k],jk=j+dj[k];
        if(ik<0||jk<0||ik>=n||jk>=m)continue;
        trvsal(ik,jk);
    }
}

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)forr(j,0,m){
        cin >> A[i][j];
        if(A[i][j]=='H')h.push_back({i,j});
        else if(A[i][j]=='C'){x=i;y=j;}
    }
    trvsal(x,y);
    cout << cnt;

    return 0;
}