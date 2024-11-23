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
    int i,j,t;
};

const int N = 1e3+10;
char A[N][N],prevdir[N][N];
char dir[]={'L','R','U','D'};
int dis[2][N][N],n,m;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
queue<Non> q;
vector<char> ans;

int main(){macos;

    cin >> n >> m;

    forr(i,0,n){
        forr(j,0,m){
            dis[0][i][j]=dis[1][i][j]=1e9;
            cin >> A[i][j];
            if(A[i][j]=='A')q.push({i,j,0}),dis[0][i][j]=0,prevdir[i][j]='S';
            else if(A[i][j]=='M')q.push({i,j,1}),dis[1][i][j]=0;
        }
    }

    while(!q.empty()){
        auto [i,j,t] = q.front();
        q.pop();

        if(dis[0][i][j]<dis[1][i][j]&&(i==0||j==0||i==n-1||j==m-1)){
            while(prevdir[i][j]!='S'){
                if(prevdir[i][j]=='R')ans.push_back('R'),j--;
                else if(prevdir[i][j]=='L')ans.push_back('L'),j++;
                else if(prevdir[i][j]=='D')ans.push_back('D'),i--;
                else ans.push_back('U'),i++;
            }
            reverse(ans.begin(),ans.end());
            cout << "YES" << endll << ans.size() << endll;
            for(char ch:ans)cout << ch;
            return 0;
        }

        forr(k,0,4){
            int ik = i+di[k];
            int jk = j+dj[k];

            if(ik<0||jk<0||ik>=n||jk>=m||A[ik][jk]=='#'||dis[t][ik][jk]<=dis[t][i][j]+1)continue;
            dis[t][ik][jk]=dis[t][i][j]+1;
            if(!t)prevdir[ik][jk]=dir[k];
            q.push({ik,jk,t});
        }
    }

    cout << "NO";

    // forr(i,0,n){
    //     forr(j,0,m){
    //         if(A[i][j]=='#')cout << '-' << sp;
    //         else cout << dis[0][i][j] << sp;
    //     }
    //     cout << endll;
    // }
    // cout << endll;
    // forr(i,0,n){
    //     forr(j,0,m){
    //         if(A[i][j]=='#')cout << '-' << sp;
    //         else cout << dis[1][i][j] << sp;
    //     }
    //     cout << endll;
    // }
    // forr(i,0,n){
    //     forr(j,0,m){
    //         cout << prevdir[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    return 0;
}