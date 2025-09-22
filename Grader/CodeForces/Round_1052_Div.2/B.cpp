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
    int n,m;
    cin >> n >> m;

    map<int,int> all,a[n];
    forr(i,0,n){
        int l;
        cin >> l;
        forr(j,0,l){
            int x;
            cin >> x;
            a[i][x]++;
            all[x]++;
        }
    }
    
    int cnt = 0;
    forr(i,0,n){
        for(auto [num,freq]:a[i]){
            all[num] -= freq;
            if(!all[num])all.erase(num);
        }
        cnt += (all.size()==m);
        for(auto [num,freq]:a[i]){
            all[num] += freq;
        }
    }

    cout << (cnt>=2?"YES":"NO") << endll;
}

int main(){macos;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}