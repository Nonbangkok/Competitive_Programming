#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1000;

int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int cnt=0,chk=0;
bool visited[N][N];
vector<char> A[N];

bool is_valid(int n,int i,int j){
    if(i<0||j<0||i>=n||j>=n||A[i][j]=='T')return false;
    return !visited[i][j];
}

void trvsal(int n,int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;

    while(!q.empty()){
        int lvl=q.size();
        cnt++;
        while(lvl--){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            forr(k,0,4){
                if(A[i][j]=='E'){
                    chk=1;
                    break;
                }
                if(is_valid(n,i+di[k],j+dj[k])){
                    q.push({i+di[k],j+dj[k]});
                    visited[i+di[k]][j+dj[k]]=true;
                }
            }
        }
        if(chk){
            cout << cnt-1;
            break;
        }
    }
}

int main() {macos;

    int n,si,sj;
    char temp;
    cin >> n;
    forr(i,0,n){
        forr(j,0,n){
            cin >> temp;
            A[i].push_back(temp);
            if(temp=='S'){
                si=i;
                sj=j;
            }
        }
    }

    trvsal( n,si,sj);

    return 0;
 }