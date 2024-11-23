#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e5+10;
vector<ll> A(N),sq(int(ceil(sqrt(N))));
int n,q,sz,sq_sz;

ll query(int l,int r){
    ll res=0;

    while(l<r&&l%sz!=0)res+=A[l++];

    while(l+sz-1<=r&&l%sz==0){
        res+=sq[l/sz];
        l+=sz;
    }

    while(l<=r)res+=A[l++];

    return res;
}

void update(int idx,ll val){
    A[idx]=val;

    int l=(idx/sz)*sz;
    int r=min(n-1,l+sz-1);

    sq[l/sz]=0;

    forr(i,l,r+1)sq[l/sz]+=A[i];
}

void build(){
    sz=ceil(sqrt(n));
    sq_sz=ceil(n/sz);

    forr(i,0,n)sq[i/sz]+=A[i];
}

int main(){macos;

    ll a,b,c;
    cin >> n >> q;
    forr(i,0,n)cin >> A[i];
    build();
    while(q--){
        cin >> a >> b >> c;
        if(a==1)update(--b,c);
        else cout << query(--b,--c) << endll;
    }

    return 0;
}