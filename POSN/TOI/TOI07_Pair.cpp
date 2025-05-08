#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10, SZ = 2 * N;
ll n,x,y,ans;
ll a[N];

struct Fenwick{
    ll fw[SZ];

    Fenwick(){
        forr(i,0,SZ)fw[i] = 0;
    }

    void update(ll idx, ll val){
        for(ll i=idx;i<SZ;i+=i&-i)fw[i] += val;
    }

    ll query(ll idx){
        ll sum = 0;
        for(ll i=idx;i>0;i-=i&-i)sum += fw[i];
        return sum;
    }
}fw1,fw2;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> x >> y,a[y] = x;
    forr(i,1,n+1){
        ans += fw1.query(N-a[i]) + fw2.query(N-a[i]) * a[i];
        fw1.update(N-a[i],a[i]),fw2.update(N-a[i],1);
    }

    cout << ans;

    return 0;
}