#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<vector<int>> multiply(int a,int b,vector<vector<int>> &A,vector<vector<int>> &B){
    vector<vector<int>> tmp(a,vector<int>(b));
    forr(i,0,a){
        forr(j,0,b){
            tmp[i][j]=0;
            forr(k,0,a)tmp[i][j]+=A[i][k]*B[k][j];
        }
    }
    return tmp;
}

int main(){macos;

    vector<vector<int>> M={{1,1},{1,0}};
    vector<vector<int>> ans={{1},{0}};
    int n;
    cin >> n;

    while(n){
        if(n&1)ans=multiply(2,1,M,ans);
        M=multiply(2,2,M,M);
        n>>=1;
    }
    cout << ans[0][0];

    return 0;
}