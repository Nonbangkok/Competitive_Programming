#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,q,x;
int dp[2][N];
vector<int> orchid;

void LIS(int s){
    vector<int> lis;
    forr(i,0,n){
        auto it = lower_bound(lis.begin(),lis.end(),orchid[i]);
        dp[s][i] = it - lis.begin();
        if(it==lis.end())lis.push_back(orchid[i]);
        else *it = orchid[i];
    }
}

int main(){macos;

    cin >> n >> q;
    forr(i,0,n)cin >> x,orchid.push_back(x);

    LIS(0);
    reverse(orchid.begin(),orchid.end());
    LIS(1);

    while(q--){
        cin >> x;
        cout << min(dp[0][x],dp[1][n-x-1]) << endll;
    }

    return 0;
}