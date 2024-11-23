#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int bisearch(int *A,int f,int l,int n){
    int m=(f+l)/2;
    if(A[m]==n)return m;
    else if(A[m]<n)bisearch(A,m+1,l,n);
    else bisearch(A,f,m-1,n);
    return -1;
}

int main() {macos;

    int n;
    cin >> n;
    int A[n],num;

    forr(i,0,n){
        cin >> A[i];
    }
    cin >> num;

    cout << bisearch(A,0,n-1,num);

    return 0;
 }
