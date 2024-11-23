#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=100;
int n,m,cntorange,cnt;
int A[N][N];
bool visited[N][N];
int di[]={0,1, 0,-1};
int dj[]={1,0,-1, 0};
queue<pair<int,int>> q;

bool is_Valid(int i,int j){
    if(i<0||j<0||i>=n||j>=m||A[i][j]!=1)return false;
    return !visited[i][j];
}

void trvsal(){
    while(!q.empty()){
        int lvl=q.size();
        cnt++;
        while(lvl--){
            int i = q.front().first;
            int j = q.front().second;
            visited[i][j]=true;
            q.pop();

            if(A[i][j]==1)cntorange--;
            forr(k,0,4){
                if(is_Valid(i+di[k],j+dj[k])){
                    q.push({i+di[k],j+dj[k]});
                    visited[i+di[k]][j+dj[k]]=true;
                }
            }
        }
    }
}

int main() {macos;

    int t;
    cin >> t;
    while(t--){
        cntorange=0,cnt=-1;
        memset(visited,false,sizeof(visited));
        cin >> n >> m;
        forr(i,0,n){
            forr(j,0,m){
                cin >> A[i][j];
                if(A[i][j]==2)q.push({i,j});
                if(A[i][j]==1)cntorange++;
            }
        }
        trvsal();
        cntorange? cout << -1 << endll:
        cout << cnt << endll;
    }

    return 0;
 }
