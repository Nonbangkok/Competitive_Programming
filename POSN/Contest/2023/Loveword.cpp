#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll A[51];
void solve(ll k,ll n){
    if(k==1)cout << 'L';
    else if(k==2)cout << 'O';
    else if(k==3)cout << 'V';
    else if(k==4)cout << 'E';
    else{
        if(n>A[k-4]+A[k-3]+A[k-2])solve(k-1,n-(A[k-4]+A[k-3]+A[k-2]));
        else if(n>A[k-4]+A[k-3])solve(k-2,n-(A[k-4]+A[k-3]));
        else if(n>A[k-4])solve(k-3,n-A[k-4]);
        else solve(k-4,n);
    }
}

int main() {macos;

    forr(i,0,5)A[i]=1;
    forr(i,5,51)A[i]=A[i-1]+A[i-2]+A[i-3]+A[i-4];
    for(auto i:A)cout << i << sp;cout << endll;

    ll q;
    cin >> q;
    while(q--){
        ll k,n;
        cin >> k >> n;
        solve(k,n);
        cout << endll;
    }

    return 0;
}