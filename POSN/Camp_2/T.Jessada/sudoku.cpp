#include <bits/stdc++.h>
#include <unistd.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int nn=3;
const int n=9;
int table[n][n],row[n][n],col[n][n],cnt=0,blk[nn][nn][n];

void show(){
    forr(i,0,n){
        if(i%nn==0){
            cout << endll;
        }
        forr(j,0,n){
            if(j%nn==0){
                cout << sp;
            }
            cout << table[i][j]+1;
        }
        cout << endll;
    }
    usleep(1);
    system("clear");
}

void nonbk(int x,int y){
    forr(i,0,n){
        if(row[i][x]==0&&col[i][y]==0&&blk[x/nn][y/nn][i]==0){
            table[x][y] = i;
            row[i][x]=1;
            col[i][y]=1;
            blk[x/nn][y/nn][i]=1;
            if(x==n-1 && y==n-1){
                show();
                //cout << cnt++<<endll;
                //usleep(1);
                //system("clear");
                }else{
                if(y==n-1){nonbk(x+1,0);}else{
                    nonbk(x,y+1);}
            }
            row[i][x]=0;
            col[i][y]=0;
            blk[x/nn][y/nn][i]=0;
        }
    }
}

int main() {macos;

    nonbk(0,0);

    return 0;
 }
