#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n;
    cin >> n;
    vector<pair<int,int>> table;
    forr(i,0,n){
        int a,b;
        cin >> a >> b;
        table.push_back({a,1});
        table.push_back({b,0});
    }
    sort(table.begin(),table.end());
    int cnt=0,mx=-1;
    for(auto i : table){
        if(i.second){
            cnt++;
            mx=max(cnt,mx);
        }else{
            cnt--;
        }
    }
    cout << mx;

    return 0;
}