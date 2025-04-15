#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m,k,mx;
int A[110][10010],dp[110][10010];

int main(){macos;

    cin >> n >> m >> k;
    forl(i,n,0){
        forr(j,1,m+1){
            cin >> A[i][j];
            if(i==1)dp[i][j] = A[i][j];
        }
    }

    forr(i,2,n+1){
        deque<pair<int,int>> dq;
        forr(j,1,k+2){
            while(!dq.empty()&&dp[i-1][j]>=dp[dq.back().first][dq.back().second])dq.pop_back();
            dq.push_back({i-1,j});
        }
        forr(j,1,m+1){
            while(!dq.empty()&&abs(j-dq.front().second)>k)dq.pop_front();
            dp[i][j] = A[i][j] + dp[dq.front().first][dq.front().second];
            if(j+k+1<=m){
                while(!dq.empty()&&dp[i-1][j+k+1]>=dp[dq.back().first][dq.back().second])dq.pop_back();
                dq.push_back({i-1,j+k+1});
            }
        }
    }

    forr(j,1,m+1)mx = max(mx,dp[n][j]);
    cout << mx;

    return 0;
}