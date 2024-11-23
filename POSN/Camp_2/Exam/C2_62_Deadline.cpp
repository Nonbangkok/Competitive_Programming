#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[22000];
void dfs(int u){
    if(A[u*2])dfs(u*2);
    if(A[u*2+1])dfs(u*2+1);
    cout << A[u] << sp;
}

int main(){macos;

    int t,n,idx;
    cin >> t;
    while(t--){
        idx=1;
        cin >> n;
        while(A[idx]){
            if(A[idx]<n)idx=idx*2+1;
            else idx=idx*2;
        }
        A[idx]=n;
    }
    dfs(1);

    return 0;
}