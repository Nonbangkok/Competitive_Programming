#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=10;
int n,m,x[N],y[N],z[N],a[N],b[N],c[N],chk[N],mn=INT_MAX;
void trvsal(int ix,int iy,int iz,int ia,int ib,int ic,int sum){
    if(ia>=n&&ib>=n&&ic>=n)mn=min(mn,sum);
    forr(i,0,m){
        if(chk[i])continue;
        chk[i]=1;
        int dis=(ix-x[i])*(ix-x[i])+(iy-y[i])*(iy-y[i])+(iz-z[i])*(iz-z[i]);
        trvsal(x[i],y[i],z[i],ia+a[i],ib+b[i],ic+c[i],sum+dis);
        chk[i]=0;
    }
}

int main() {macos;

    int stx,sty,stz;
    cin >> n >> stx >> sty >> stz >> m;
    forr(i,0,m)cin >> x[i] >> y[i] >> z[i] >> a[i] >> b[i] >> c[i];
    trvsal(stx,sty,stz,0,0,0,0);
    cout << mn;

    return 0;
}