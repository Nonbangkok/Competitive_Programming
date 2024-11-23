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
int par[N],n,m,a,b,cnt = 0;
vector<int> ans;

int find(int x){
    if(par[x]!=x)par[x] = find(par[x]);
    return par[x];
}

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)par[i] = i;
    forr(i,0,m){
        cin >> a >> b;
        par[find(b)] = par[find(a)];
    }

    forr(i,1,n){
        if(find(i)!=find(i+1)){
            ans.push_back(i);
            par[find(i+1)] = par[find(i)];
            cnt++;
        }
    }

    cout << cnt << endll;
    for(int i:ans)cout << i << sp << i+1 << endll;

    return 0;
}