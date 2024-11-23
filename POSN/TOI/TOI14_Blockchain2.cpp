#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int M=1e9+7;
map<vector<pair<int,int>>,int> mp;
int main(){macos;

    int n,q,m,a,b;
    cin >> n >> q;

    while(n--){
        cin >> m;
        vector<pair<int,int>> A;
        forr(i,0,m-1){
            cin >> a >> b;
            A.push_back({min(a,b),max(a,b)});
        }
        sort(A.begin(),A.end());
        mp[A]++;
    }
    while(q--){
        cin >> m;
        vector<pair<int,int>> A;
        forr(i,0,m-1){
            cin >> a >> b;
            A.push_back({min(a,b),max(a,b)});
        }
        sort(A.begin(),A.end());
        cout << mp[A] << endll;
    }

    return 0;
}