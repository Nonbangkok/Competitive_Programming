#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (long long i = a; i < n; i++)
#define forl(i, a, n) for (long long i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
ll A[N],fw[N];

void update(ll idx,ll val){
    for(ll i=idx;i<=N;i+=(i&-i))fw[i]+=val;
}

ll query(ll idx){
    ll sum=0;
    for(ll i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int main(){macos;

    int n,q;
    cin >> n >> q;
    forr(i,1,n+1)cin >> A[i],update(i,A[i]);
    cout << query(n) << endll;
    forr(i,0,q){
        int a,b;
        cin >> a >> b;a++;
        update(a,b-A[a]);
        A[a]=b;
        cout << query(n) << endll;
    }

    return 0;
}