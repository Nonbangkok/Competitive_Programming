#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e6+10;
int pat[N],sandw[N];
int main(){macos;

    int n,x;
    cin >> n;
    forr(i,1,n+1){
        cin >> x;
        if(x>0){
            sandw[i]=sandw[i-1]+x;
            pat[i]=pat[i-1];
        }else{
            pat[i]=pat[i-1]+(-x);
            sandw[i]=sandw[i-1];
        }
    }

    //forr(i,0,n)cout << pat[i] << sp << sandw[i] << endll;

    int q;
    cin >> q;
    forr(i,0,q){
        int a,b;
        cin >> a >> b;
        int idx=lower_bound(pat,pat+n-1,b+pat[a-1])-pat;
        cout << sandw[idx]-sandw[a-1] << endll;
    }

    return 0;
}