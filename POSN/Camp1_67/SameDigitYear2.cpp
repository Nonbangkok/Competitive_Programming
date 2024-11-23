#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e7;
vector<pair<int,int>> hist;

bool chk(int n){
    bool vis[10] = {false};
    while(n){
        if(vis[n%10])return true;
        vis[n%10] = true;
        n/=10;
    }
    return false;
}

int main(){macos;

    int t,l,r;
    cin >> t;

    int cnt = 0;
    forr(i,1,N+1){
        if(chk(i)){
            cnt++;
        }else if(cnt){
            hist.push_back({i-1,cnt});
            cnt = 0;
        }else cnt = 0;
    }
    hist.push_back({N,cnt});

    // forr(i,0,hist.size()){
    //     cout << setw(10) << i << setw(10) << hist[i].first << setw(10) << hist[i].second << endll;
    // }

    while(t--){
        int mx = 0,cnt = 0;
        cin >> l >> r;
        forr(i,l,r+1){
            if(chk(i))cnt++;
            else cnt = 0;
            mx = max(mx,cnt);
        }
        cout << mx << endll;
    }

    return 0;
}