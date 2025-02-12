#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5+10;
vector<pair<int,int>> stick;
int banana[N];
bool visited[N];
int m,n,k,a,b,st;

int main(){macos;

    cin >> m >> n >> k;
    forr(i,0,n){
        cin >> a >> b;
        stick.emplace_back(b,a);
    }
    cin >> st;

    sort(stick.begin(),stick.end());


    for(auto [x,h]:stick){
        
    }

    return 0;
}