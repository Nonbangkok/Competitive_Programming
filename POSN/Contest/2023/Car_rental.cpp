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

    ll sum=0,t,n,money;
    cin >> t >> n;

    while(n>0){
        if(n>=8){sum+=300;n-=15;}
        else if(n>=7){sum+=250;n-=7;}
        else if(n>=6){sum+=200;n-=6;}
        else if(n>=3){sum+=150;n-=5;}
        else if(n>=2){sum+=100;n-=2;}
        else if(n>=1){sum+=50;n-=1;}
    }

    while(t--){
        cin >> money;
        (money>=sum)?cout << money-sum:cout << -1;
        cout << endll;
    }

    return 0;
}