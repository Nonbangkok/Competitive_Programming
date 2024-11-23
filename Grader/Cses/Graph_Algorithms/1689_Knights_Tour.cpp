#include <bits/stdc++.h>
#include <unistd.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int table[8][8],x,y,mark=1;
bool visited[8][8],chk=0;
const int di[]={-2,-2,-1,-1,1,1,2,2};
const int dj[]={-1,1,-2,2,-2,2,-1,1};

void dfs(int i,int j){
    if(visited[i][j])return;
    visited[i][j]=true;
    table[i][j]=mark++;

    if(mark==64)chk=1;

    // forr(l,0,8){
    //     forr(o,0,8){
    //         cout << setw(2) << table[l][o] << sp;
    //     }
    //     cout << endll;
    // }
    // usleep(1);
    // system("clear");
    
    forr(k,0,8){
        int ik=i+di[k];
        int jk=j+dj[k];

        if(ik<0||jk<0||ik>=8||jk>=8||visited[ik][jk])continue;
        dfs(ik,jk);
        if(chk)return;
        table[ik][jk]=0;
        visited[ik][jk]=false;
        mark--;
    }
}

int main(){macos;

    cin >> x >> y;
    dfs(y-1,x-1);

    forr(i,0,8){
        forr(j,0,8){
            cout << table[i][j] << sp;
        }
        cout << endll;
    }

    return 0;
}