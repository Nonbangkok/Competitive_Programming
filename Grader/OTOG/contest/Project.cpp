#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e3+10;
int A[N][N];
int main(){macos;

    int n,m,q;
    cin >> n >> m >> q;
    forr(i,0,n)forr(j,0,m)cin >> A[i][j];

    int i,j;
    ll sum=0,cnt=0;
    char ch;
    while(q--){
        cin >> i >> j >> ch;
        if(ch=='U')i--;
        else if(ch=='D')i++;
        else if(ch=='R')j++;
        else if(ch=='L')j--;
        if(i<0||j<0||i>=n||j>=m){
            cnt++;
            continue;
        }
        sum+=A[i][j];
    }
    cout << sum << sp << cnt;


    return 0;
}