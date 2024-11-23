#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=110;
ll ai[N],aj[N],bi[N],bj[N];
int main(){macos;

    ll n,m,tmp,sum=0,mx=0;
    cin >> n >> m;
    forr(i,1,n+1)forr(j,1,m+1){
        cin >> tmp;
        sum+=tmp;
        ai[i]+=tmp;
        aj[j]+=tmp;
    }

    forr(i,1,n+1)forr(j,1,m+1){
        cin >> tmp;
        bi[i]+=tmp;
        bj[j]+=tmp;
    }

    forr(i,1,n+1)mx=max(mx,sum-ai[i]+bi[i-1]+bi[i+1]);
    forr(j,1,m+1)mx=max(mx,sum-aj[j]+bj[j-1]+bj[j+1]);
    cout << mx;

    return 0;
}