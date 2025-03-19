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
    int u,v,w;

    bool operator < (const Non &rhs)const{
        return w>rhs.w;
    }
};

int fp(vector<int> &p,int x){
    if(p[x]!=x)p[x] = fp(p,p[x]);
    return p[x];
}

int mst_weight(vector<pair<int,int>> e,vector<int> w){
    int n = w.size(),ans = 0;
    vector<int> p[n];
    priority_queue<Non> q;

    forr(i,0,n)q.push({e[i].first,e[i].second,w[i]});
    forr(i,0,n)p[i] = i;

    while(!q.empty()){
        auto [u,v,w] = q.top();
        q.pop();

        if(fp(u)==fp(v))continue;
        p[fp(v)] = fp(u);
        ans += w;
    }

    return ans;
}

// Score : 85
// vector<pair<int,int>> route(int N, vector<int> W){
//     int n = N, m = W.size();
//     vector<pair<int,int>> ans(m);
//     int st = m - n + 1;
//     for(int i=st,j=1;i<m;i++,j++)ans[i] = {j,j+1};

//     int remain = st;
//     int i = 3, j = 1,idx = 0;
//     while(remain--){
//         ans[idx++] = {j++,i};
//         if(i-j==1)i++,j=1;
//     }

//     return ans;
// }

// Score : 65
vector<pair<int,int>> route(int N, vector<int> W){
    int n = N, m = W.size();
    vector<pair<int,int>> ans(m);
    int st = m - n + 1;
    for(int i=st,j=1;i<m;i++,j++)ans[i] = {j,j+1};

    int remain = st;
    int i = 3, j = 1,idx = st - 1;
    while(remain--){
        ans[idx--] = {j++,i};
        if(i-j==1)i++,j=1;
    }

    return ans;
}

int main(){macos;

    int n,m;
    cin >> n >> m;
    vector<int> w(m);
    forr(i,0,m)cin >> w[i];
    vector<pair<int,int>> ans = route(n,w);

    for(auto [i,j]:ans)cout << i << sp << j << endll;cout << endll;


    cout << mst_weight(ans,w);

    return 0;
}