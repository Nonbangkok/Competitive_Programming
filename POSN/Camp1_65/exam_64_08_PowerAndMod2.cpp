#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int a,b,m,cnt=0;
ll poww(int a,int k){
    if(k==0)return 1;

    ll x=poww(a,k/2)%m;
    if(k%2==0)return x%m*x%m;
    return (x%m*x%m*a)%m;
}

int main(){macos;

    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> m;
        cout << poww(a,b)%m << endll;
    }

    return 0;
}