#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int find(int *A,int n,int x){
    forr(i,0,n)if(A[i]==x)return i;
    return -1;
}

int main(){macos;

    int n,x;
    cin >> n;
    int A[n];
    forr(i,0,n)cin >> A[i];
    cin >> x;
    cout << find(A,n,x);

    return 0;
}