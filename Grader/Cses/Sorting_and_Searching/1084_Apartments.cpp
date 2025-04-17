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
int n,m,k,cnt;
int a[N],b[N];

int main(){macos;

    cin >> n >> m >> k;
    forr(i,0,n)cin >> a[i];
    forr(i,0,m)cin >> b[i];
    
    sort(a,a+n);
    sort(b,b+m);

    int i = 0, j = 0;
    while(i<n&&j<m){
        if(a[i]-k<=b[j]&&b[j]<=a[i]+k)cnt++,i++,j++;
        else if(a[i]<b[j])i++;
        else j++;
    }

    cout << cnt;

    return 0;
}