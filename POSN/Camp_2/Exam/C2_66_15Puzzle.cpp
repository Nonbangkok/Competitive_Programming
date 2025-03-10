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
    int a[4][4];
    int i, j, d, c;

    Non(int arr[4][4], int x, int y, int depth, int cost){
        memcpy(a, arr, sizeof(a));
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
map<string,bool> visited;

int distance(int A[4][4]){
    int dis = 0;
    forr(i,0,4)forr(j,0,4){
        int x, y;
        
        if(A[i][j] == 0)x = 3,y = 3;
        else x = (A[i][j]-1)/4,y = (A[i][j]-1)%4;

        dis += abs(i-x) + abs(j-y);
    }
    return dis;
}

string to_string(int A[4][4]){
    string s = "";
    forr(i,0,4)forr(j,0,4)s += A[i][j] + '0';
    return s;
}

int main(){macos;

    int mp[4][4];
    int x,y;

    forr(i,0,4)forr(j,0,4){
        cin >> mp[i][j];
        if(mp[i][j]==0)x = i, y = j;
    }

    q.push(Non(mp,x,y,0,distance(mp)));
    while(!q.empty()){
        auto [u,i,j,d,c] = q.top();
        q.pop();

        if(distance(u)==0){
            cout << d;
            return 0;
        }

        visited[to_string(u)] = 1;

        forr(k,0,4){
            int ik = i+di[k];
            int jk = j+dj[k];

            if(ik<0||ik>=4||jk<0||jk>=4)continue;

            swap(u[i][j],u[ik][jk]);
            if(visited[to_string(u)]){swap(u[i][j],u[ik][jk]);continue;}

            q.push(Non(u,ik,jk,d+1,distance(u)));
            swap(u[i][j],u[ik][jk]);
        }
    }

    return 0;
}