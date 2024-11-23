#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

bool bit[int(2e6)];

int main() {macos;

    int n,m;
    cin >> n >> m;
    int A[n],B[m];
    forr(i,0,n)cin >> A[i];
    forr(i,0,m)cin >> B[i];

    forr(i,0,n){
        forr(j,i+1,n){
            bit[A[i]+A[j]]=true;
        }
    }

    forr(i,0,m){
        if(bit[B[i]])cout << "YES" << endll;
        else cout << "NO" << endll;
    }


    return 0;
 }
