#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//2d grid

const int N=21;
int n,x,y,ans=-6;
int A[N][N];
bool visited[N][N];
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};

bool is_Valid(int i,int j){
    if(i<0||j<0||i>=n||j>=n)return false;
    return !visited[i][j];
}

void trvsal(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;

    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        q.pop();
        ans=max(ans,A[i][j]);
        forr(k,0,4){
            if(is_Valid(i+di[k],j+dj[k])&&A[i][j]<A[i+di[k]][j+dj[k]]){
                q.push({i+di[k],j+dj[k]});
                visited[i+di[k]][j+dj[k]]=true;
            }
        }
    }
}

int main() {macos;

    cin >> n >> x >> y;
    forr(i,0,n){
        forr(j,0,n){
            cin >> A[i][j];
            if(A[i][j]==100)A[i][j]=-6;
        }
    }
    trvsal(y-1,x-1);
    cout << ans;

    return 0;
 }
