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
    if(i==n)mx=max(mx,sum+A[i][j]);
    else{
        forr(k,1,n+1){
            if(chk[k])continue;
            chk[k]=true;
            sSearch(k,j+1,sum+A[i][j]);
            chk[k]=false;
        }
    }
}

int main(){macos;

    cin >> n;
    forr(i,1,n+1)forr(j,1,n+1)cin >> A[i][j];
    forr(i,1,n+1){
        chk[i] = true;
        sSearch(i,1,0);
        chk[i] = false;
    }
    cout << mx;

    return 0;
}