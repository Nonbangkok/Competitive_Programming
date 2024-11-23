#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int n,w,l;
    char c;
    cin >> c >> n >> w >> l;

    int k=2*n+1;
    for(int i=0;i<k*(l+1);i++){
        for(int j=0;j<w;j++){
            int ik=i%k;
            int jk=(j+k-i/k)%k;
            if(ik<=jk+n && ik>=jk-n && ik+jk>=n && ik+jk<=3*n) cout << c;
            else cout << '.';
        }
        cout << endll;
    }

    return 0;
} 