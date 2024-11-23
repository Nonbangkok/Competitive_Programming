#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef unsigned long long ll;
using namespace std;
const ll M=1e9+7;

vector<vector<ll>> mul(int a,int b,vector<vector<ll>> &A,vector<vector<ll>> &B){
    vector<vector<ll>> tmp(a,vector<ll>(b,0));
    forr(i,0,a){
        forr(j,0,b){
            forr(k,0,a){
                tmp[i][j]+=(A[i][k]*B[k][j]);
                tmp[i][j]%=M;
            }
        }
    }
    return tmp;
}

int main(){macos;

    vector<vector<ll>> M={{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
    vector<vector<ll>> ans={{1},{1},{1},{1}};
    ll n;
    cin >> n;

    if(n<=4){cout << 1;return 0;}
    n-=4;
    while(n){
        if(n&1)ans=mul(4,1,M,ans);
        M=mul(4,4,M,M);
        n>>=1;
    }
    cout << ans[0][0];

    return 0;
}