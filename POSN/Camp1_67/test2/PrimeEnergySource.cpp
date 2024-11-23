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

    ll n,k,sum = 0 ,cnt = 0;
    cin >> n >> k;
    if(n%2==0)n--;
    for(int i=n+1;;i++){
        if(i==1)continue;
        bool chk = true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                chk = false;
                break;
            }
        }
        if(chk)sum += i,cnt++;
        if(cnt==k)break;
    }
    cout << sum;

    return 0;
}