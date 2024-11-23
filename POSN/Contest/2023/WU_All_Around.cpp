#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n,A[12][12],mx=-1;
bool chk[12];

void sSearch(ll i,ll j,ll sum){
    if(i==n){
        mx=max(mx,sum);
    }else{
        if(i-1>=0){
            chk[i-1]=true;
            sSearch(i-1,j+1,sum+A[i][j]);
            chk[i-1]=false;
        }
        if(i+1<n){
            chk[i+1]=true;
            sSearch(i+1,j+1,sum+A[i][j]);
            chk[i+1]=false;
        }
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n)forr(j,0,n)cin >> A[i][j];
    forr(i,0,n)sSearch(i,0,0);
    cout << mx;

    return 0;
}