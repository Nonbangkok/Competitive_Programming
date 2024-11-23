#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001;
char A[N][N],prevm[N][N];
bool visited[N][N];
int n,m,chk=1;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
char ds[]={'L','R','U','D'};
pair<int,int> st,en;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)forr(j,0,m){
        cin >> A[i][j];
        if(A[i][j]=='A')st={i,j};
        else if(A[i][j]=='B')en={i,j};
    }

    queue<pair<int,int>> q;
    q.push(st);
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();

        if(A[i][j]=='B'){
            chk=0;
            break;
        }

        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<0||jk<0||ik>=n||jk>=m||visited[ik][jk]||A[ik][jk]=='#')continue;
            q.push({ik,jk});
            prevm[ik][jk]=ds[k];
            visited[ik][jk]=true;
        }
    }
    if(chk){cout << "NO";return 0;}

    string s="";
    int dis=0;
    while(st!=en){
        auto [i,j]=en;
        if(prevm[i][j]=='L')en.second++;
        if(prevm[i][j]=='R')en.second--;
        if(prevm[i][j]=='U')en.first++;
        if(prevm[i][j]=='D')en.first--;
        s+=prevm[i][j];
        dis++;
    }
    reverse(s.begin(),s.end());
    cout << "YES" << endll << dis << endll << s;

    return 0;
}