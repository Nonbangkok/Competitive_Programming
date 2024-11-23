#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int n,tmp;
    ll sum=0;
    cin >> n;
    forr(i,0,n){cin >> tmp;sum+=tmp;}
    if(sum%3==0)cout << 'Y';
    else cout << 'N';


    return 0;
}