#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//2D grid

const int N=100;
int n,m,times=0,chk=0,si,sj;
char ch[N][N];
int visited[N][N];
queue<tuple<int,int,int>> q;

bool is_Valid(int i,int j){
    if(i<0||j<0||i>=n||j>=m)return false;
    if(visited[i][j]){
        chk=1;
        si=i;
        sj=j;
    }
    return !visited[i][j];
}

void pushf(int i,int j,int direct){
    if(is_Valid(i,j)){
        q.push({i,j,direct});
        visited[i][j]=true;
    }
}

void trvsal(int i,int j){
    q.push({i,j,0});
    visited[i][j]=true;

    while(!q.empty()&&!chk){
        int lvl=q.size();
        times++;
        while(lvl--){
            i= get<0>(q.front());
            j= get<1>(q.front());
            int direct = get<2>(q.front());
            q.pop();
            // cout << endll << i << sp << j << sp << direct;
            // cout << endll;

            if((ch[i][j]=='R'||ch[i][j]=='B')&&direct!=1){
                pushf(i,j+1,3);
            }
            if((ch[i][j]=='D'||ch[i][j]=='B')&&direct!=2){
                pushf(i+1,j,4);
            }
            //if(chk) cout << "Before";
            if((ch[i][j-1]=='R'||ch[i][j-1]=='B')&&direct!=3){
                pushf(i,j-1,1);
            }
            if((ch[i-1][j]=='D'||ch[i-1][j]=='B')&&direct!=4){
                pushf(i-1,j,2);
            }

            // cout << endll;
            // forr(i,0,n){
            //     forr(j,0,m){
            //         cout << visited[i][j] << sp;
            //     }   
            //     cout << endll;
            // } 
            
            if(chk){
                //cout << endll;
                cout << times+1 << endll << si+1 << sp << sj+1;
                //cout << sp << ch[si][sj];
                lvl=0;
            }
        }
    }
}

int main() {macos;

    cin >> n >> m;
    forr(i,0,n){
        forr(j,0,m){
            cin >> ch[i][j];
        }
    }
    trvsal(0,0);
    /* 
    cout << endll;
    forr(i,0,n){
        forr(j,0,m){
            cout << visited[i][j] << sp;
        }
        cout << endll;
    } 
    */

    return 0;
 }
 /*
4 4 
B R D N
D R B D
R R R D
N N N N

3 4
R B B D
D N R B
R R R N

4 4
R R R D
D R R B
D R N N
R R R B

4 4
B R R D
D B R B
D R D N
R R R B
 */