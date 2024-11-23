#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e5+10;
int app[N],apart[N];
int main(){macos;

    int n,m,k;
    cin >> n >> m >> k;
    forr(i,0,n)cin >> app[i];
    forr(i,0,m)cin >> apart[i];
    sort(app,app+n);
    sort(apart,apart+m);

    int i = 0, j = 0, cnt = 0;
    while(i<n && j<m){
        if(app[i]-k<=apart[j]&&apart[j]<=app[i]+k){
            cnt++;
            i++;
            j++;
        }else if(app[i]<apart[j])i++;
        else j++;
    }
    cout << cnt;

    return 0;
}