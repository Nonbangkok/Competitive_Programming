#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int a,k,m=1000,cnt=0;
int poww(int a,int b){
    if(b==0)return 1;

    int x=poww(a,b/2)%m;
    if(b%2==0)return x%m*x%m;
    return (x%m*x%m*a)%m;
}

int main(){macos;

    int t;
    cin >> t;
    while(t--){
        cin >> a >> k;
        cout << poww(a,k)%m << endll;
    }

    return 0;
}