#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define forr(i, a, n) for (long long i = a; i < n; i++)
typedef long long ll;
using namespace std;

struct Non{
    ll wi,wj,oi,oj;
}Node[20001];
ll n,m,k,p,mndis=m+n-2,mnt=0;
ll dp[18][20001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k >> p;
    mndis=m+n-2;
    forr(i,0,k){
        cin >> Node[i].wi >> Node[i].wj >> Node[i].oi >> Node[i].oj;
        dp[1][i]=Node[i].wi+Node[i].wj-2;
        if(mndis>dp[1][i]+m+n-(Node[i].oi+Node[i].oj)){
            mndis=dp[1][i]+m+n-(Node[i].oi+Node[i].oj);
            mnt=1;
        }
    }

    forr(t,2,p+1)forr(i,0,k){
        dp[t][i]=LONG_MAX;
        forr(j,0,k)dp[t][i]=min(dp[t][i],dp[t-1][j]+abs(Node[j].oi-Node[i].wi)+abs(Node[j].oj-Node[i].wj));
        if(mndis>dp[t][i]+m+n-(Node[i].oi+Node[i].oj)){
            mndis=dp[t][i]+m+n-(Node[i].oi+Node[i].oj);
            mnt=t;
        }
    }

    cout << mndis << ' ' << mnt;

    return 0;
}