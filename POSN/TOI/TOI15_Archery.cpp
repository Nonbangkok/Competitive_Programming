#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=5e5+10;
pair<ll,ll> A[N]; //pos,high
ll qs[N],n,sum,mnh=LONG_MAX,mn=LONG_MAX,pos=LONG_MAX,tmp;
int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> A[i].second,mnh=min(mnh,A[i].second);
    forr(i,1,n+1)cin >> A[i].first,sum+=A[i].first;
    sort(A+1,A+n+1);
    forr(i,1,n+1)qs[i]=qs[i-1]+A[i].second;

    forr(i,1,n+1){
        if(A[i].first>mnh)break;
        tmp=sum-(A[i].first*n)+qs[i-1];
        if(mn>tmp)mn=tmp,pos=A[i].first;
        else if(mn==tmp)pos=min(pos,A[i].first);
    }
    cout << pos << sp << mn;

    return 0;
}