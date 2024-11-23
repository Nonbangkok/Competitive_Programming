#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e7 , M = 470000;
int dp[2],idx[M],peak[M],l[10],r[10];
int t,mx,st,en,ix;

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

    cin >> t;
    forr(i,0,t)cin >> l[i] >> r[i];

    int now = 1, prev = 0;
    for(int i=2;i<=N;i++){
        if(chk(i))dp[now] = dp[prev] + 1;
        else dp[now] = 0;
        if(dp[prev]&&!dp[now]){
            idx[ix] = i - 1;
            peak[ix] = dp[prev];
            ix++;
        }else{
            forr(j,0,t){
                if(i-1==l[j]||i-1==r[j]){
                    idx[ix] = i - 1;
                    peak[ix] = dp[prev];
                    ix++;   
                }
            }
        }
        swap(now,prev);
    }
    idx[ix] = N;
    peak[ix] = dp[prev];
    ix++;

    // for(int i=1;i<=N;i++){
    //     if(chk(i))dp[i] = dp[i-1] + 1;
    //     if(dp[i-1]&&!dp[i]){
    //         idx[ix] = i-1;
    //         peak[ix] = dp[i-1];
    //         ix++;
    //     }
    // }

    // forr(i,0,ix)cout << setw(4) << i << sp;
    // cout << endll;
    // forr(i,0,ix)cout << setw(4) << idx[i] << sp;
    // cout << endll;
    // forr(i,0,ix)cout << setw(4) << peak[i] << sp;
    // cout << endll;

    // forr(i,0,ix){
    //     cout << setw(10) << i << setw(10) << idx[i] << setw(10) << peak[i] << endll;
    // }

    forr(i,0,t){
        st = lower_bound(idx,idx+ix,l[i])-idx;
        en = upper_bound(idx,idx+ix,r[i])-idx;
        mx = 0;
        forr(j,st,en)mx = max(mx,peak[j]);
        cout << mx << endll;
    }

    return 0;
}