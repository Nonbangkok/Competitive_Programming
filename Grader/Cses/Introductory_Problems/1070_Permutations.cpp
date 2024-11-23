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

    int n;
    cin >> n;
    if(n==1)cout << 1;
    else if(n<=3)cout << "NO SOLUTION";
    else{
        for(int i=2;i<=n;i+=2)cout << i << sp;
        for(int i=1;i<=n;i+=2)cout << i << sp;
    }

    return 0;
}