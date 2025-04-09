#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1<<20;
int n,a,sum;
int dis[N];
queue<int> q;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a;
        sum = (sum << 1) + a;
    }

    forr(i,0,N)dis[i] = 1e9;
    dis[sum] = 0;
    q.push(sum);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        forr(i,0,n){
            int v = u ^ (1 << i);
            if(i!=0) v ^= (1 << (i-1));
            if(i!=n-1) v ^= (1 << (i+1));
            if(dis[v]<=dis[u]+1)continue;
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }
    
    cout << (dis[0]!=1e9?dis[0]:-1);

    return 0;
}