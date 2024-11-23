/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;

vector<ll> A;
void solve(int n,int k){
    if(n==0) cout << 'A' << endll;
    else if(n==1) cout << 'B' << endll;
    else{
        if(A[n-2]>=k) solve(n-2,k);
        else solve(n-1,k-A[n-2]);
    }
}

int main() {macos;

    A.push_back(1);
    A.push_back(1);
    forr(i,0,51){
        A.push_back(A[i]+A[i+1]);
    }
    int t,n,k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        n-=1;
        solve(n,k);
    }

  return 0;
}
