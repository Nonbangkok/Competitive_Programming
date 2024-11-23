#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m;
    cin >> n >> m;
    pair<int,int> A[n];
    forr(i,0,n){
        int temp;
        cin >> temp;
        A[i]={temp,i};
    }
    sort(A,A+n);

    int q;
    while(m--){
        cin >> q;
        int l=0,r=n-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(A[mid])
        }
    }
    //not finished

    return 0;
}