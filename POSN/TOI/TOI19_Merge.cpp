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
int x[N],s[N],y[N],t[N];
int main(){macos;

    int n,m,q,a,b,k;
    cin >> n >> m >> q;

    forr(i,0,n)cin >> x[i];
    forr(i,1,n+1){cin >> s[i];s[i]+=s[i-1];}
    forr(i,0,m)cin >> y[i];
    forr(i,1,m+1){cin >> t[i];t[i]+=t[i-1];}

    while(q--){
        cin >> a >> b >> k;
        int l=INT_MIN,r=INT_MAX,mid;
        while(l<r){
            mid=(l+r)>>1;
            int i=upper_bound(x,x+n,mid)-x;
            int j=upper_bound(y,y+m,(mid-b)/a)-y;
            if(s[i]+t[j]>=k)r=mid;
            else l=mid+1
        }
        cout << l << endll;
    }

    return 0;
}