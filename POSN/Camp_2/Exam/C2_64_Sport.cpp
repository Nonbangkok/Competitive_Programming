#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int table[10000];
int main() {macos;

    int n;
    cin >> n;
    int  k,A[n];
    forr(i,0,n)cin >> A[i];
    cin >> k;
    sort(A,A+n);
    forr(i,0,n)table[A[i]]=1;
    forr(i,0,k+1){
        forr(j,0,n){
            if(i-A[j]>=0)table[i]+=table[i-A[j]];
        }
    }
    //forr(i,0,k+1)cout << table[i] << sp;cout << endll;

    cout << table[k];

    return 0;
}