#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    vector<pair<int,int>> event;
    int n;
    cin >> n;

    forr(i,0,n){
        int a,b;
        cin >> a >> b;
        event.push_back({a,1});
        event.push_back({b,-1});
    }
    sort(event.begin(),event.end());

    int cnt=0,mx=-1;
    for(auto [time,e]:event)mx=max(mx,cnt+=e);
    cout << mx;

    return 0;
}