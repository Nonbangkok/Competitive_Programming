#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,w,cnt;
int a[N];

int main(){macos;

    cin >> n >> w;
    forr(i,0,n)cin >> a[i];

    sort(a,a+n);

    int i = 0, j = n-1;
    while(i<j){
        if(a[i]+a[j]<=w)i++;
        cnt++;
        j--;
    }

    cout << cnt + (i==j);

    return 0;
}