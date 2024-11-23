#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=50;
int n,m,lvl=-1,chk=1;
char ch[N][N];
bool visited[N][N];
queue<tuple<int,int,int>> q;
int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};

bool is_Valid(int i,int j,int state){
    if(!state&&ch[i][j]=='D') return false;
    if(i<0||j<0||i>=n||j>=m||ch[i][j]=='X')return false;
    return !visited[i][j];
}

void trvsal(int i,int j){
    q.push({i,j,1});
    visited[i][j]=true;

    while(!q.empty()&&chk){
        int qsize=q.size();
        lvl++;
        while(qsize--){
            int i=get<0>(q.front());
            int j=get<1>(q.front());
            int state=get<2>(q.front());
            q.pop();

            if(ch[i][j]=='D'&&state){
                chk=0;
                break;
            }

            forr(k,0,4){
                int ik=i+di[k];
                int jk=j+dj[k];
                if(is_Valid(ik,jk,state)){
                    q.push({ik,jk,state});
                    visited[ik][jk]=true;
                }
            }
        }
    }
}

int main() {macos;

    int sti,stj;
    cin >> n >> m;
    forr(i,0,n){
        forr(j,0,m){
            cin >> ch[i][j];
            if(ch[i][j]=='*'){
                q.push({i,j,0});
                visited[i][j]=true;
            }
            if(ch[i][j]=='S'){
                sti=i;
                stj=j;
            }
        }
    }
    trvsal(sti,stj);
    !chk?cout << lvl:
    cout << "KAKTUS";

    return 0;
 }