#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=101;
char A[N][N];
int n,sti,stj;
bool visited[N][N];
int di[]={0,0,-1,-1,-1,1,1,1};
int dj[]={-1,1,0,-1,1,0,-1,1};

int count(int i,int j){
    int cntf=0;
    forr(k,0,8){
        int ik=i+di[k];
        int jk=j+dj[k];

        if(ik<0||jk<0||ik>=n||jk>=n)continue;
        if(A[ik][jk]=='*')cntf++;
    }
    return cntf;
}

int main() {macos;

    cin >> n >> stj >> sti;
    forr(i,0,n){
        forr(j,0,n){
            cin >> A[i][j];
        }
    }
    int sum=0;
    queue<pair<int,int>> q;
    q.push({sti-1,stj-1});
    visited[sti-1][stj-1]=true;
    while(!q.empty()){
        int i=q.front().first,j=q.front().second;
        q.pop();
    
        int cntstar=count(i,j);
        if(cntstar){
            sum+=cntstar;
        }else{
            forr(k,0,8){
                int ik=i+di[k];
                int jk=j+dj[k];

                if(ik<0||jk<0||ik>=n||jk>=n)continue;
                if(visited[ik][jk])continue;
                q.push({ik,jk});
                visited[ik][jk]=true;
            }
        }
    }
    cout << sum;

    return 0;
}