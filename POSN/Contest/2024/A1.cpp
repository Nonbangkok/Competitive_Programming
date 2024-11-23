#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1001,M=1e9+7;
ll A[N][N],dp[N][N],dpu[N][N],dpl[N][N];
int main(){macos;

    string s;
    int n,m;
    cin >> n >> m;
    forr(i,1,n+1){
        cin >> s;
        forr(j,1,m+1){
            A[i][j]=s[j-1]-'0';
        }
    }
    if(A[1][1]==0)dp[1][1]=1;
    forr(i,1,n+1){
        forr(j,1,m+1){
            if(A[i][j]){
                dpu[i][j]=dp[i-1][j]+dpu[i-1][j];
                dpl[i][j]=dp[i][j-1]+dpl[i][j-1];
                dpu[i][j]%=M;
                dpl[i][j]%=M;
            }else{
                dp[i][j]+=dp[i-1][j]+dp[i][j-1]+dpu[i-1][j]+dpl[i][j-1];
                dp[i][j]%=M;
            }
        }
    }

    // forr(i,1,n+1){
    //     forr(j,1,m+1){
    //         cout << dp[i][j] << sp;
    //     }
    //     cout << endll;
    // }

    cout << dp[n][m];

    return 0;
}