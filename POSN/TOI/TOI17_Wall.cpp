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
char A[N][N];
bool water[N][N];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
int n,m;

int trvsal(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    int cnt=0;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(A[i][j]=='-')continue; //debug when grid have push q doubly
        A[i][j]='-';
        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];
            if(ik<0||jk<0||ik>=n||jk>=m)continue;
            if(water[ik][jk]&&A[ik][jk]=='.')cnt++;
            if(A[ik][jk]=='X')q.push({ik,jk});
        }
    }
    return cnt;
}

void flow(int i,int j){
    water[i][j]=1;
    forr(k,0,4){
        int ik=i+di[k];
        int jk=j+dj[k];
        if(ik<0||jk<0||ik>=n||jk>=m) continue;
        if(A[ik][jk]=='X'||water[ik][jk]) continue;
        flow(ik,jk);
    }
}

int main() {macos;

    cin >> n >> m;
    forr(i,0,n){
        cin >> A[i];
    }

    forr(i,0,n){
        water[i][0]=1;
        water[i][m-1]=1;
    }
    forr(i,0,m){
        water[0][i]=1;
        water[n-1][i]=1;
    }
    forr(i,0,n){
        flow(i,0);
        flow(i,m-1);
    }
    forr(i,0,m){
        flow(0,i);
        flow(n-1,i);
    }

    int mx=-1;
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]=='X'){
                mx=max(mx,trvsal(i,j));
            }
        }
    }
    cout << mx << endll;

    return 0;
}