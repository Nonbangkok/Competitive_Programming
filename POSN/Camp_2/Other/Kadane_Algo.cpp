#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int A[N];

int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)cin >> A[i];

    int mx=INT_MIN,sum=0;

    forr(i,0,n){
        sum = max(sum+A[i],A[i]);
        mx = max(mx,sum);
    }

    // forr(i,0,n){
    //     sum += A[i];
    //     mx = max(mx,sum);
    //     sum = max(sum,0);
    // }

    cout << mx;

    return 0;
}