#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const ll N=1e6+1,M=1e9+7;
ll fw[N],n,x,cnt=0;

void update(ll idx){
    for(ll i=idx;i<=N;i+=(i&-i))fw[i]++;
}

ll query(ll idx){
    ll sum=0;
    for(ll i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int main(){macos;

    cin >> n;
    forr(i,1,n+1){
        cin >> x;
        cnt+=query(N-x);
        cnt%=M;
        update(N-x);
    }
    cout << cnt;

    return 0;
}