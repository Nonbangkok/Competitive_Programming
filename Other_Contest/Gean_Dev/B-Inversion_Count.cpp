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
    int a[n+1];
    forr(i,0,n)cin >> a[i];

    int cnt = 0;
    forr(i,0,n){
        forr(j,i+1,n){
            if(a[i]>a[j])cnt++;
        }
    }
    cout << cnt;

    return 0; 
}