#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e4 + 10; 
int w[N],l[N],minweight[N],mxsz[N];
vector<int> ans;

int main(){macos;

    int n;
    cin >> n;
    forr(i,1,n+1)cin >> w[i] >> l[i];

    forr(i,1,n+1)minweight[i] = 1e9;

    forr(i,1,n+1){
        forl(k,i,0){
            if(l[i]>=minweight[k-1]){
                minweight[k] = min(minweight[k],minweight[k-1]+w[i]);
                mxsz[i] = max(mxsz[i],k);
            }
        }
    }

    forr(i,1,n+1)cout << minweight[i] << sp;
    cout << endll;
    forr(i,1,n+1)cout << mxsz[i] << sp;

    return 0;
}