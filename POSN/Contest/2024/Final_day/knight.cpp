#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int x,y,d;
};

const int N=1010;
int A[N][N];
bool visited[N][N];
const int di[]={-2,-2,-1,-1,1,1,2,2};
const int dj[]={-1,1,-2,2,-2,2,-1,1};
int main(){macos;

    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;

    queue<Non> q;
    q.push({a,b,0});
    visited[a][b]=true;
    while(!q.empty()){
        auto [i,j,de]=q.front();
        q.pop();

        if(i==c&&j==d){cout << de;return 0;}

        forr(k,0,8){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<=0||jk<=0||ik>n||jk>n||visited[ik][jk])continue;
            q.push({ik,jk,de+1});
            visited[ik][jk]=true;
        }
    }

    return 0;
}