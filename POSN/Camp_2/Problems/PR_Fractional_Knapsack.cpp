#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 110;
float V[N],W[N];
float t,n,w;
vector<pair<float,int>> worth;

int main(){macos;

    cin >> t;

    while(t--){
        cin >> n >> w;
        forr(i,0,n)cin >> V[i] >> W[i],worth.push_back({V[i]/W[i],i});
        sort(worth.rbegin(),worth.rend());
        float ans = 0;
        for(auto [ratio,i]:worth){
            if(w == 0)break;
            float take = min(W[i],w);
            ans += take*ratio;
            w -= take;
        }
        coutf(2, ans) << endll;
        worth.clear();
    }

    return 0;
}