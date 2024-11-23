#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2000000;
ll a[N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> a[i];
    ll l=0,r=2147483648,m;
    bool chk;

    while(l<=r){
        m=(l+r)/2,chk=1;

        ll box=-1;
        forr(i,0,n){

            if(a[i]<=m)continue;
            if(box==-1)box=a[i];
            else if(a[i]==box)box=-1;
            else {chk=0;break;}
        }
        
        if(chk)r=m-1;
        else l=m+1;
        //cout << l << sp << m << sp << r << sp << chk << endll;
    }
    cout << l;

    return 0;
}