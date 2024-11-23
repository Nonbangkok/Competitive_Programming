#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
priority_queue<int> q;
int A[N];
int main(){macos;

    int n,m,k,sum=0;
    cin >> n >> m >> k;k--;
    forr(i,0,m)cin >> A[i];
    forr(i,1,m)q.push(A[i]-A[i-1]-1),sum+=A[i]-A[i-1]-1;
    while(k--&&!q.empty())sum-=q.top(),q.pop();
    cout << sum;

    return 0;
}