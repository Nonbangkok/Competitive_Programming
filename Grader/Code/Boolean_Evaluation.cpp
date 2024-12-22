// link : https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM

int solve(string & exp,int a,int b,int k){
    if(exp[k]=='|')return a|b;
    if(exp[k]=='&')return a&b;
    if(exp[k]=='^')return a^b;
}

long long evaluateExp(string & exp) {
    const int M = 1e9+7;
    int n = exp.size();
    long long dp[n][n][2];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j][0]=dp[i][j][1]=0;
    for(int i=0;i<n;i++){
        if(exp[i]=='T')dp[i][i][1] = 1;
        if(exp[i]=='F')dp[i][i][0] = 1;
    }
    for(int sz = 2;sz<n;sz+=2)
        for(int l=0;l<n-sz;l+=2){
        int r = l+sz;
        for(int k=l+1;k<r;k+=2)
            for(int a=0;a<2;a++)
                for(int b=0;b<2;b++)
                    if(dp[l][k-1][a]&&dp[k+1][r][b])dp[l][r][solve(exp,a,b,k)] = (dp[l][r][solve(exp,a,b,k)]+(dp[l][k-1][a]*dp[k+1][r][b])%M)%M;
    }
    return dp[0][n-1][1];
}