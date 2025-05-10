#include "tsp.h"
#include <vector>
#include <limits>
#include <iostream>
using namespace std;

const int N = 21;
int dp[N][1<<N];

int tsp(const vector<vector<int>>& dist) {
    int n = dist[0].size() , mn = 1e9;
    for(int i=0;i<n;i++)for(int j=0;j<(1<<n);j++)dp[i][j] = 1e9;
    dp[0][1] = 0;
    for(int j=1;j<(1<<n);j+=2){
        for(int i=0;i<n;i++){
            if(!(j&(1<<i)))continue;
            if(dp[i][j]==1e9)continue;
            for(int k=0;k<n;k++){
                if(j&(1<<k))continue;
                dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)],dp[i][j]+dist[i][k]);
                if((j|(1<<k))==(1<<n)-1)mn = min(mn,dp[k][j|(1<<k)]+dist[k][0]);
            }
        }
    }
    return mn;
}
// cd tsp && make && ./build/main