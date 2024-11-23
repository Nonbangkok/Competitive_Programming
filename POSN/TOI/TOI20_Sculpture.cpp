#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e4+10; 
int w[N],l[N],dp[N][2],cnt[N][2];
vector<int> ans;
int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> w[i] >> l[i];

    forr(i,1,n+1){
        forr(j,0,2){
            if(dp[i-1][j] <= l[i] && cnt[i][j] < cnt[i-1][j] + 1){
                dp[i][j] = dp[i-1][j] + w[i];
                cnt[i][j] = cnt[i-1][j] + 1;
            }else if(cnt[i][j] == cnt[i-1][j] + 1){
                dp[i][j] = min(dp[i][j],dp[i-1][j] + w[i]);
            }else{
                dp[i][j] = dp[i-1][j];
                cnt[i][j] = cnt[i-1][j];
            }
        }
        if(cnt[i][1]<=cnt[i][0]&&i!=1&&i!=n){
            dp[i][1] = 0;
            cnt[i][1] = cnt[i][0];
            ans.push_back(i);
        }
    }
    forr(i,1,n+1){
        forr(j,0,2){
            cout << dp[i][j] << sp;
        }
        cout << endll;
    }
    cout << endll;
    forr(i,1,n+1){
        forr(j,0,2){
            cout << cnt[i][j] << sp;
        }
        cout << endll;
    }
    cout << endll;
    cout << dp[n][0] << sp << dp[n][1];
    cout << endll << cnt[n][0] << sp << cnt[n][1];
    cout << endll;
    cout << max(cnt[n][0],cnt[n][1]) << endll;
    for(int i:ans)cout << i << sp;

    return 0;
}