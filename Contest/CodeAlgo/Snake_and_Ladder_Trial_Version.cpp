#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n;

int solve(int x){
    if(x<=6)return 1;
    else if(x&1)return solve(x-5) + 1;
    return solve(x-6) + 1;
}

int main(){macos;

    cin >> n;
    cout << solve(n);

    return 0;
}