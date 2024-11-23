#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int di[]={0,-1,1};
const int dj[]={1,0,0};

struct Non{
    int x,y,cnt,t;

    bool operator <(const Non &rhs)const{
        return cnt>rhs.cnt;
    }
};

int main(){macos;

    int n,m,st;
    cin >> n >> m >> st;
    char A[n][m];
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    priority_queue<Non> q;
    q.push({st-1,0,0,0});
    while(!q.empty()){
        auto [i,j,c,ty]=q.top();
        q.pop();
        if(j==m-1){cout << c;return 0;}
        A[i][j]='#';
        forr(k,0,3){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<0||jk<0||ik>=n||jk>=m||A[ik][jk]=='#')continue;
            q.push({ik,jk,c+(k!=ty),k});
        }
    }
    cout << -1;

    return 0;
}