#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int m=3,n=3,cnt=0;
int G[100][100];
bool visited[100][100];
queue<pair<int,int> > A;
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};

bool is_valid(int i,int j){
    if(i<0 || j<0 || i>=m || j>=n)return false;
    return !visited[i][j];
}

void trvsal(int i,int j){
    A.push({i,j});
    visited[i][j]=true;
    
    while(!A.empty()){
        int lvl=A.size();
        cnt++;
        cout << "count " << cnt << endll;
        while(lvl--){
            i=A.front().first;
            j=A.front().second;
            cout << G[i][j] << endll;
            A.pop();
            
            forr(k,0,4){   
                if(is_valid(i+di[k],j+dj[k])){
                    A.push({i+di[k],j+dj[k]});
                    visited[i+di[k]][j+dj[k]]=true;
                }
            }
        }
    }
}

int main() {macos;
    int k=1;
    memset(visited,false,sizeof(visited));
    forr(i,0,m){
        forr(j,0,n){
            G[i][j] = k;
            k++;
        }
    }
    trvsal(0,0);

    return 0;
 }
/* 
1 2 3
4 5 6
7 8 9
 */