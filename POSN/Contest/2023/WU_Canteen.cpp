#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
int n,e,x,y;
queue<int> q[N];

int main(){macos;

    cin >> n;
    
    forr(i,0,n){
        cin >> e;
        if(e==1){
            cin >> x >> y;
            q[y].push(x);
        }else if(e==2){
            cin >> y;
            if(!q[y].empty())q[y].pop();
        }else if(e==3){
            cin >> y;
            if(!q[y].empty())cout << q[y].front() << endll;
            else cout << -1 << endll;
        }else{
            cin >> y;
            cout << q[y].size() << endll;
        }
    }

    return 0;
}