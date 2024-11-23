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
        int n;
        cin >> n;
        char ch;
        bool a[2][n];
        ll sum = 0;
        forr(i,0,2)forr(j,0,n){
            cin >> ch;
            a[i][j] = (ch=='x'?1:0);
        }
        forr(i,0,2)forr(j,1,n-1){
            if(i==0 && (!a[i][j-1]&&!a[i][j+1]&&!a[i+1][j]&&a[i+1][j-1]&&a[i+1][j+1]))sum++;
            if(i==1 && (!a[i][j-1]&&!a[i][j+1]&&!a[i-1][j]&&a[i-1][j-1]&&a[i-1][j+1]))sum++;
        }
        cout << sum << endll;
    }

    return 0;
}