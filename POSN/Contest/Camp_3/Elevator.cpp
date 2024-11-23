#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1<<21;
ll cnt[N],sum[N];
int main(){macos;

    ll n,m,tmp;
    cin >> n >> m;
    forr(i,0,1<<n)cnt[i]=sum[i]=1e9;
    forr(i,0,n)cin >> tmp,cnt[1<<i]=0,sum[1<<i]=tmp;
    forr(i,0,1<<n)forr(j,0,n){
        if(cnt[i]>cnt[i^(1<<j)]+cnt[1<<j]+(sum[i^(1<<j)]+sum[1<<j]>=m)){
            cnt[i]=cnt[i^(1<<j)]+cnt[1<<j]+(sum[i^(1<<j)]+sum[1<<j]>=m);
            if(sum[i^(1<<j)]+sum[1<<j]>m)sum[i]=min(sum[i^(1<<j)],sum[1<<j]);
            else if(sum[i^(1<<j)]+sum[1<<j]==m)sum[i]=0;
            else sum[i]=sum[i^(1<<j)]+sum[1<<j];
        }
    }
    cout << cnt[(1<<n)-1]+(sum[(1<<n)-1]>0);


    return 0;
}