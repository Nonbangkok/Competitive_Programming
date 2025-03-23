#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5010;
int n,q,a,b;
ll qs[N],c[N],mn;

int main(){macos;

    cin >> n >> q;
    forr(i,1,n)cin >> qs[i],qs[i] += qs[i-1];
    forr(i,0,n)cin >> c[i];

    // forr(i,1,n)cout << qs[i] << sp;cout << endll << endll;

    while(q--){
        cin >> a >> b;
        // cout << qs[a] << sp << qs[b] << sp << c[a] << endll;
        if(a<b){
            mn = abs(qs[b]-qs[a])*c[a];
            // forr(i,0,a)mn = min(mn,abs(qs[a]-qs[i])*c[a]+abs(qs[b]-qs[i])*c[i]);
            forr(i,0,n)mn = min(mn,abs(qs[a]-qs[i])*c[a]+abs(qs[b]-qs[i])*c[i]);
        }else{
            mn = (qs[a]-qs[b])*c[a];
            // forr(i,b+1,a)mn = min(absmn,(qs[a]-qs[i])*c[a]+abs(qs[i]-qs[b])*c[i]);
            forr(i,0,n)mn = min(mn,abs(qs[a]-qs[i])*c[a]+abs(qs[i]-qs[b])*c[i]);
        }
        cout << mn << endll;
        // cout << endll;
    }

    return 0;
}