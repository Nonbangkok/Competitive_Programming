#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e5+10;
int n,q,A[N],dp[N][2];

void LIS(int x){
    int tmp[n],ans=0;
    forr(i,0,n){
        int idx=lower_bound(tmp,tmp+ans,A[i])-tmp;
        if(idx==ans)ans++;
        tmp[idx]=A[i];
        dp[i][x]=idx;
    }
}

int main(){macos;

    cin >> n >> q;
    forr(i,0,n)cin >> A[i];

    LIS(0);
    reverse(A,A+n);
    LIS(1);
    

    // forr(i,0,2){
    //     forr(j,0,n){
    //         cout << dp[j][i] << sp;
    //     }
    //     cout << endll;
    // }

    int x;
    forr(i,0,q){
        cin >> x;
        cout << min(dp[x][0],dp[n-x-1][1]) << endll;
    }

    return 0;
}