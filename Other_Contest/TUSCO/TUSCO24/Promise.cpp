#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int a[int(1e5+10)], b[11];
int main(){macos;

    int n,k;
    cin >> n >> k;
    forr(i,0,n)cin >> a[i];
    forr(i,0,k)cin >> b[i];

    for(int i=0;i<n-k+1;i++){
        int diff = a[i]-b[0];
        for(int j=1;j<k;j++){
            if(a[i+j]-b[j]==diff){
                if(j==k-1){
                    cout << i+1;
                    return 0;
                }
            }else break;
        }
    }

    return 0;
}