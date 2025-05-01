#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m,a,b,pre=1,color,des;
ll ans;
char ch;
unordered_map<char,int> mp = {{'R',0},{'G',1},{'B',2}};
vector<pair<int,int>> event;

int main(){macos;

    cin >> m >> n;
    forr(i,0,n){
        cin >> a >> b;
        event.push_back({a,1});
        event.push_back({b+1,-1});
    }
    event.push_back({m+1,0});
    cin >> ch;
    des = mp[ch];

    sort(event.begin(),event.end());

    for(auto [x,t]:event){
        ans += (x-pre)*((des-color+3)%3);
        pre = x;
        color = (color + t) % 3;
    }
    cout << ans;

    return 0;
}