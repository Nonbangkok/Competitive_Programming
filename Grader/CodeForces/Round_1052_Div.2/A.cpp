#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;

    map<int,int> counts;
    forr(i,0,n){
        int x;
        cin >> x;
        counts[x]++;
    }

    vector<int> v;
    for(auto [a,b]:counts)v.push_back(b);
    sort(v.rbegin(),v.rend());

    int mx = 0;
    forr(i,0,v.size())mx = max(mx,(i+1)*v[i]);

    cout << mx << endll;
}

int main(){macos;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}