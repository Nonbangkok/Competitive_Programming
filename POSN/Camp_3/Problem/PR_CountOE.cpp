#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5;
int A[N],fw[N];

void update(int idx,int val){
    for(int i=idx;i<=N;i+=(i&-i))fw[i]+=val;
}

int query(int idx){
    int sum=0;
    for(int i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int main(){macos;

    int n,q,x,l,r;
    cin >> n;

    forr(i,1,n+1){
        cin >> A[i];
        if(A[i]&1)update(i,A[i]&1);
    }

    cin >> q;
    forr(i,0,q){
        cin >> x >> l >> r;
        if(x==0&&(A[l]&1)!=(r&1)){update(l,(r&1)?1:-1);A[l]=r;}
        else if(x==1)cout << (r-l)-(query(r)-query(l-1))+1 << endll;
        else if(x==2)cout << query(r)-query(l-1) << endll;
    }


    return 0;
}