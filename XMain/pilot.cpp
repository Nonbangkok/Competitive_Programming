#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
int n,m;
ll ans;
int mountain[N];
pair<int,int> plane[N];

int main(){macos;

    cin >> n >> m;
    forr(i,1,n+1)cin >> mountain[i];
    forr(i,1,m+1)cin >> plane[i].first,plane[i].second = i;
    sort(plane+1,plane+m+1);

    forr(i,1,n+1)cout << mountain[i] << sp;cout << endll;
    forr(i,1,m+1)cout << plane[i].first << sp;cout << endll;

    return 0;
}