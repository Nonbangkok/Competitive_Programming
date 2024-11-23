#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//using quicksum 2d
int main() {macos; 

    vector<pair<int,int>> spinger,mango;
    int n,m,d,k;
    cin >> n >> m >> d >> k;
    vector<vector<int>> qs(n+2,vector<int>(m+2,0));
    string s;

    forr(i,1,n+1){
        cin >> s;
        forr(j,1,m+1){
            if(s[j-1]=='M')mango.push_back({i,j});
            if(s[j-1]=='S')spinger.push_back({i,j});
        }
    }

    for(auto [x,y] : spinger){
        qs[max(1,x-d)][max(1,y-d)]+=1;
        qs[max(1,x-d)][min(m+1,y+d+1)]-=1;
        qs[min(n+1,x+d+1)][max(1,y-d)]-=1;
        qs[min(n+1,x+d+1)][min(m+1,y+d+1)]+=1;
    }

    // forr(i,0,n+2){
    //     forr(j,0,m+2){
    //         cout << qs[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    forr(i,1,n+1)forr(j,1,m+1)qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];

    // cout << endll;
    // forr(i,0,n+2){
    //     forr(j,0,m+2){
    //         cout << qs[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    int ans=0;
    for(auto i : mango)if(qs[i.first][i.second]>=k)ans++;
    cout << ans << endll;

    return 0;
}