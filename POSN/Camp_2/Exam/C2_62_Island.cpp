#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m,cnt=0;
char ch[100][100];
bool visited[100][100];
int di[]={1,0,-1,-1,-1, 0, 1,1};
int dj[]={1,1, 1, 0,-1,-1,-1,0};

bool is_Valid(int i,int j){
    if(i<0||j<0||i>=n||j>=m||ch[i][j]!='X')return false;
    return !visited[i][j];
}

void trvsal(int i,int j){
    visited[i][j]=true;
    forr(k,0,8){
        if(is_Valid(i+di[k],j+dj[k])){
            trvsal(i+di[k],j+dj[k]);
        }
    }
}

int main() {macos;

    cin >> m >> n;
    forr(i,0,n){
        forr(j,0,m){
            cin >> ch[i][j];
        }
    }
    forr(i,0,n){
        forr(j,0,m){
            if(ch[i][j]=='X'&&!visited[i][j]){
                trvsal(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
 }
