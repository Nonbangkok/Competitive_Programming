#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=2002;
int n,m;
bitset<N> A[N];
int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={1,0,-1,1,-1,1,0,-1};

void trvsal(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    A[i][j]=false;

    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();

        forr(k,0,8){
            int ik=i+di[k];
            int jk=j+dj[k];
            if(ik<0||jk<0||ik>=n||jk>=m||!A[ik][jk])continue;
            q.push({ik,jk});
            A[ik][jk]=false;
        }
    }
}

int main() {macos;

    string s;
    cin >> n >> m;
    forr(i,0,n){
        cin >> s;
        forr(j,0,m){
            A[i][j]=s[j]-'0';
        }
    }
    int cnt=0;
    forr(i,0,n){
        forr(j,0,m){
            if(A[i][j]){
                trvsal(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}