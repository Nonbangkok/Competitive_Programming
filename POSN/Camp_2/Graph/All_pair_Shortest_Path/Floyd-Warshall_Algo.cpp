#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int V=5;

int dis[V][V];
void trvsal(int graph[V][V]){

    forr(i,0,V){
        forr(j,0,V){
            dis[i][j]=graph[i][j];
        }
    }

    forr(k,0,V){
        forr(j,0,V){
            forr(i,0,V){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    
}

int main() {macos;

    int graph[V][V];
    forr(i,0,V){
        forr(j,0,V){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=(int)1e9;
        }
    }
    graph[0][1]=3;
    graph[0][2]=8;
    graph[0][4]=-4;
    graph[1][4]=7;
    graph[1][3]=1;
    graph[2][1]=4;
    graph[3][0]=2;
    graph[3][2]=-5;
    graph[4][3]=6;

    trvsal(graph);

    forr(i,0,V){
        forr(j,0,V){
            cout << setw(2) << dis[i][j] << sp;
        }
        cout << endll;
    }


    return 0;
}