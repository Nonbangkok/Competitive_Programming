#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 100;
int A[N];
int n,m,mx;

int main(){macos;

    cin >> n >> m;
    forr(i,0,m)cin >> A[i],mx=max(mx,A[i]);

    int l = mx,r = 1e7,mid;
    while(l<r){
        mid = (l+r) >> 1;

        int cnt = 0,kps = 0;
        forr(i,0,m){
            if(kps+A[i]<=mid)kps += A[i];
            else kps = A[i],cnt++;
        }

        if(cnt>=n)l = mid+1;
        else r = mid;
    }
    cout << l;

    return 0;
}