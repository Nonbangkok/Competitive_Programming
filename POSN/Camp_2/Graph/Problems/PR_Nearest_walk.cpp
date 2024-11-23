#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1000;
char ch[N][N];
int n,m,chk,cnt;
bool visited[N][N];
int di[]={0,1, 0,-1};
int dj[]={1,0,-1, 0};

bool is_Valid(int i,int j){
    if(i<0||j<0||i>=n||j>=m||ch[i][j]=='#')return false;
    return !visited[i][j];
}

void trvsal(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;

    while(!q.empty()&&chk){
        int lvl=q.size();
        cnt++;
        while(lvl--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(ch[i][j]=='B'){
                chk=0;
                break;
            }
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

    int t,sti,stj;
    cin >> t;
    while(t--){
        cin >> n >> m;
        forr(i,0,n){
            forr(j,0,m){
                cin >> ch[i][j];
                if(ch[i][j]=='A'){
                    sti=i;
                    stj=j;
                }
            }
        }
        chk=1,cnt=0;
        trvsal(sti,stj);
        chk?cout << -1 << endll:
        cout << cnt-1 << endll;
    }

    return 0;
 }
