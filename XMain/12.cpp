#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e5;
int A[N];
int main(){macos;

    int n, k;
    cin >> n >> k;
    forr(i,0,n)cin >> A[i];

    int mx=0, l=0, zeros=0;
    forr(r,0,n){
        if(A[r]==0)zeros++;
        while(zeros>k){
            if (A[l]==0)zeros--;
            l++;
        }
        mx=max(mx,r-l+1);
    }

    cout << mx;

    return 0;
}