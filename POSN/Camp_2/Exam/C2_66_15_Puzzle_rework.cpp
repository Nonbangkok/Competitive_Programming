#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Table{
    int a[4][4];

    int distance(){
        int dis = 0;
        forr(i,0,4)forr(j,0,4){
            int x, y;
            
            if(a[i][j] == 0)x = 3,y = 3;
            else x = (a[i][j]-1)/4,y = (a[i][j]-1)%4;

            dis += abs(i-x) + abs(j-y);
        }
        return dis;
    }

    void print(){
        forr(i,0,4){
            forr(j,0,4)cout << a[i][j] << sp;
            cout << endll;
        }
        cout << endll;
    }

    bool operator < (const Table &rhs)const{
        forr(i,0,4)forr(j,0,4)
            if(a[i][j]!=rhs.a[i][j])return a[i][j] < rhs.a[i][j];
        return 0;
    }
};

struct Non{
    Table a;
    int i, j, d, c;

    Non(Table arr, int x, int y, int depth, int cost){
        a = arr;
        i = x;
        j = y;
        d = depth;
        c = cost;
    }

    bool operator < (const Non &rhs)const{
        return d+c>rhs.d+rhs.c;
    }
};

const int di[4] = {0,0,-1,1};
const int dj[4] = {-1,1,0,0};
priority_queue<Non> q;
map<Table,bool> visited;
map<Table,Table> pre;
vector<Table> his;

int main(){macos;

    Table mp;
    int x,y;

    forr(i,0,4)forr(j,0,4){
        cin >> mp.a[i][j];
        if(mp.a[i][j]==0)x = i, y = j;
    }

    q.push(Non(mp,x,y,0,mp.distance()));
    while(!q.empty()){
        auto [u,i,j,d,c] = q.top();
        q.pop();

        if(u.distance()==0){
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

        visited[u] = 1;

        forr(k,0,4){
            int ik = i+di[k];
            int jk = j+dj[k];
            Table v = u;

            if(ik<0||ik>=4||jk<0||jk>=4)continue;

            swap(v.a[i][j],v.a[ik][jk]);
            if(visited[v])continue;

            pre[v] = u;
            q.push(Non(v,ik,jk,d+1,v.distance()));
        }
    }

    return 0;
}