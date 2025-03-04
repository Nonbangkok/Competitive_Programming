#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6+10;
int A[N];
int n,k,p,l=INT_MAX,m,r,cnt;

int main(){macos;

    cin >> n >> k >> p;
    forr(i,0,n){
        cin >> A[i];
        l = min(l,A[i]);
        r = max(r,A[i]);
    }

    while(l<r){
        m = (l+r)>>1;

        cnt = 0;
        forr(i,0,n){
            if(A[i]>m){
                i+=p-1;
                cnt++;
            }
        }

        if(cnt>k)l = m + 1;
        else r = m;
    }

    cout << l;

    return 0;
}