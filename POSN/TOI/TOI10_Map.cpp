#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=5e4;
int m,n,a,b,mni=INT_MAX,mnj=INT_MAX,ans[201][201];
char ch1,ch2;
bool visited[N];
pair<int,int> track[N];
vector<pair<char,int>> adj[N];

void trvsal(int i,int j,int node){
    if(visited[node])return;
    visited[node]=true;
    mni=min(i,mni);
    mnj=min(j,mnj);
    track[node]={i,j};
    for(auto [ch,v]:adj[node]){
        if(ch=='U')trvsal(i-1,j,v);
        if(ch=='D')trvsal(i+1,j,v);
        if(ch=='L')trvsal(i,j-1,v);
        else trvsal(i,j+1,v);
    }
}

int main() {macos;

    cin >> m >> n;
    forr(i,0,(m*n)-1){
        cin >> a >> ch1 >> b;
        if(ch1=='U')ch2='D';
        else ch2='R';
        adj[a].push_back({ch2,b});
        adj[b].push_back({ch1,a});
    }
    trvsal(0,0,0);

    forr(k,0,(m*n)){
        auto [i,j]=track[k];
        ans[i-mni][j-mnj]=k;
    }
    forr(i,0,m){
        forr(j,0,n){
            cout << ans[i][j] << sp;
        }
        cout << endll;
    }

    return 0;
}