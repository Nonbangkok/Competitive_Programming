#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,x;
    cin >> n;
    int odd=n,even=n,combo=0,prev;
    forr(i,0,2*n){
        cin >> x;
        if(i&&((x&1)!=(prev&1)))combo=0;
        if(x&1){
            even--;
            combo++;
            if(combo>=3)even-=2;
        }else{
            odd--;
            combo--;
            if(combo<=-3)odd-=2;
        }
        if(odd<=0){
            cout << 0 << endll << x;
            return 0;
        }else if(even<=0){
            cout << 1 << endll << x;
            return 0;
        }
        prev=x;
    }

    return 0;
}