#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 256;
int maxheight[N];
int main(){macos;

    int n;
    cin >> n;

    forr(i,0,n){
        int l,h,r;
        cin >> l >> h >> r;
        forr(j,l,r)maxheight[j] = max(maxheight[j],h);
    }

    forr(i,1,256){
        if(maxheight[i-1]!=maxheight[i]){
            cout << i << ' ' << maxheight[i] << ' ';
        }
    }

    return 0;
}