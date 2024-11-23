#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int f(int a, int b){
    if(a>b)return 1;
    if(a==b)return 0;
    if(a<b)return -1;
    return 0;
}

int main(){macos;

    int t;
    cin >> t;

    while(t--){
        int a,b,c,d,sum = 0;
        cin >> a >> b >> c >> d;
        if(f(a,c)+f(b,d)>0)sum+=2;
        if(f(a,d)+f(b,c)>0)sum+=2;
        cout << sum << endl;
    }

    return 0;
}