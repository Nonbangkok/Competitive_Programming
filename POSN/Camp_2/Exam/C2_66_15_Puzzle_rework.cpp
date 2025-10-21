#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 4;

struct Board{
    int board[N][N];

    Board(){}

    Board(int a[N][N]){
        forr(i,0,N)forr(j,0,N)board[i][j] = a[i][j];
    }
    
    int distance(){
        int dis = 0;
        forr(i,0,N)forr(j,0,N){
            int x, y;

            if(!board[i][j])x = N - 1, y = N - 1;
            else x = (board[i][j]-1) / N, y= (board[i][j]-1) % N;

            dis += abs(i-x) + abs(j-y);
        }
        return dis;
    }

    void print(){
        forr(i,0,N){
            forr(j,0,N)cout << board[i][j] << sp;
            cout << endll;
        }
        cout << endll;
    }

    bool operator < (const Board &rhs)const{
        forr(i,0,N)forr(j,0,N)
            if(board[i][j]!=rhs.board[i][j])return board[i][j] < rhs.board[i][j];
        return 0;
    }
};

struct Node{
    Board board;
    int i, j, d, c;

    Node(Board a, int b, int e, int f, int g):board(a), i(b), j(e), d(f), c(g){}

    bool operator < (const Node &rhs)const{
        return d + c > rhs.d + rhs.c;
    }
};

const int di[4] = {0,0,-1,1};
const int dj[4] = {-1,1,0,0};
priority_queue<Node> q;
map<Board,bool> vis;
map<Board,Board> pre;
vector<Board> his;

int main(){macos;

    Board mp;
    int x, y;

    forr(i,0,N)forr(j,0,N){
        cin >> mp.board[i][j];
        if(!mp.board[i][j])x = i, y = j;
    }

    q.push(Node(mp,x,y,0,mp.distance()));
    while(!q.empty()){
        auto [u,i,j,d,c] = q.top();
        q.pop();

        if(!u.distance()){
            cout << d << endll << endll;
            his.push_back(u);
            while(pre.find(u)!=pre.end()){
                u = pre[u];
                his.push_back(u);
            }
            reverse(his.begin(),his.end());
            for(auto i:his)i.print();
            return 0;
        }

        vis[u] = true;

        forr(k,0,4){
            int ik = i + di[k];
            int jk = j + dj[k];
            Board v = u;

            if(ik<0||ik>=4||jk<0||jk>=4)continue;

            swap(v.board[i][j],v.board[ik][jk]);
            if(vis[v])continue;

            pre[v] = u;
            q.push(Node(v,ik,jk,d+1,v.distance()));
        }
    }

    return 0;
}