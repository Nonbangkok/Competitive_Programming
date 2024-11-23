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
    int v,w;

    Non(int a,int b):v(a),w(b){}
};

vector<Non>adj[1001];

int main(){macos;

    int v,e,a,b,c;
    cin >> v >> e;

    forr(i,0,e){
        cin >> a >> b >> c;
        adj[a].push_back(Non(b,c));
        adj[b].push_back(Non(a,c));
    }

    int src,des;
    cin >> src >> des;

    forr(i,1,v+1){
        for(auto j : adj[i])cout << j.v << sp;
        cout << endll;
    }

    return 0;
}