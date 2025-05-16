#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10, M = 1e9 + 7;
ll n,x,sum,ans;
ll a[N];
vector<ll> coor;

struct Fenwick{
    ll fw[2*N];

    void update(ll idx, ll val){
        for(ll i=idx;i<=coor.size();i+=i&-i)fw[i] += val,fw[i] %= M;
    }

    ll query(ll idx){
        ll sum = 0LL;
        for(ll i=idx;i>0;i-=i&-i)sum += fw[i],sum %= M;
        return sum;
    }
}fw;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a[i];
        coor.push_back(a[i]);
    }

    sort(coor.begin(),coor.end());
    coor.erase(unique(coor.begin(),coor.end()),coor.end());

    // forr(i,0,n){
    //     forr(j,0,i)if(a[i]>a[j])dp[i] += dp[j],dp[i] %= M;
    //     sum += dp[i];
    // }

    forr(i,0,n){
        x = upper_bound(coor.begin(),coor.end(),a[i])-coor.begin();
        sum = fw.query(x-1) + 1LL;
        fw.update(x,sum);
        ans += sum,ans %= M;
    }

    cout << ans;
        

    return 0;
}