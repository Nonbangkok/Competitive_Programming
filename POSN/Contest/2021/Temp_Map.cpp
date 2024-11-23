#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=102;
int n,m;
int A[N][N];
bool visited[N][N];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
queue<pair<int,int>> q;

bool is_Valid(int i,int j){
    if(i<0||j<0||i>=n||j>=m)return false;
    return !visited[i][j];
}

void trvsal(){
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();

        int sum=0,cnt=0;
        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];
            if(is_Valid(ik,jk)){
                sum+=A[ik][jk];
                cnt++;
            }
        }
        cnt?A[i][j]=sum/cnt:
        A[i][j]=0;
    }
}

int main() {macos;

    cin >> n >> m;
    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
            if(A[i][j]==0){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }
    trvsal();
    //cout << endll;
    forr(i,0,n){
        forr(j,0,m){
            cout << A[i][j] << sp;
        }
        cout << endll;
    }

    return 0;
 }