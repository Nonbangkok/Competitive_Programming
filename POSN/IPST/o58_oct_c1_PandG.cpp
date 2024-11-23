#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int A[101][101],visited[101][101];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
vector<pair<int,int>> ghost[1001];

struct Non{
    int dis,x,y;
};

bool solve(){
    int r,c,n,T,x,y,ti,xi,yi;
    string s;
    cin >> r >> c >> n >> T >> x >> y;
    forr(i,0,n){
        cin >> ti >> xi >> yi;
        ghost[ti].push_back({xi,yi});
    }
    forr(i,0,r){
        cin >> s;
        forr(j,0,c){
            if(s[j]=='.')A[i][j]=1e9;
            else A[i][j]=-1;
            visited[i][j]=false;
        }
    }
    queue<Non> q;
    forr(t,0,T+1){
        for(auto i : ghost[t]){
            if(A[i.first][i.second]>t){
                q.push({t,i.first,i.second});
                A[i.first][i.second]=t;
            }
        }
        ghost[t].clear();
        int sq=q.size();
        while(sq--){
            int i=q.front().x;
            int j=q.front().y;
            int dis=q.front().dis;
            q.pop();

            forr(k,0,4){
                int ik=i+di[k];
                int jk=j+dj[k];

                if(ik<0||jk<0||ik>=r||jk>=c)continue;
                if(dis+1<A[ik][jk]){
                    A[ik][jk]=dis+1;
                    q.push({dis+1,ik,jk});
                }
            }
        }
    }
    while(!q.empty())q.pop();
    // forr(i,0,r){
    //     forr(j,0,c){
    //         if(A[i][j]==1e9||A[i][j]==-1) cout << '-' << sp;
    //         else cout << A[i][j] << sp;
    //     }
    //     cout << endll;
    // }
    if(A[x][y]>0){
        q.push({0,x,y});
        visited[x][y]=true;
    }
    while(!q.empty()){
        int i=q.front().x;
        int j=q.front().y;
        int dis=q.front().dis;
        q.pop();

        if(A[i][j]>T)return true;

        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<0||jk<0||ik>=r||jk>=c)continue;
            if(visited[ik][jk])continue;
            if(A[ik][jk]>dis+1){
                q.push({dis+1,ik,jk});
                visited[ik][jk]=true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int k;
    cin >> k;
    while(k--){
        solve()?cout << "YES":cout << "NO";
        cout << endll;
    }

    return 0;
}