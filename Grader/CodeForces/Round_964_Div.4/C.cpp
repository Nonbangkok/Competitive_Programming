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

    int t;
    cin >> t;

    while(t--){
        int n,s,m,last = 0;
        bool chk = false;
        cin >> n >> s >> m;
        vector<pair<int,int>> works;
        forr(i,0,n){
            int l,r;
            cin >> l >> r;
            works.push_back({l,r});
        }
        works.push_back({m,m});

        forr(i,0,n+1){
            if(works[i].first-last>=s){
                chk = true;
                break;
            }
            last = works[i].second;
        }

        cout << (chk?"YES":"NO") << endll;
    }

    return 0;
}