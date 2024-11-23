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

    int t;
    cin >> t;

    while(t--){
        int l,r,L,R;
        cin >> l >> r >> L >> R;
        int overlap = min(r,R)-max(l,L);
        if(overlap <= -1)overlap = 1;
        else{
            if(l!=L)overlap++;
            if(r!=R)overlap++;
        }
        cout << overlap << endll;
    }

    return 0;
}