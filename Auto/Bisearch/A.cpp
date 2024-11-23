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
    int A[n];
    forr(i,0,n)cin >> A[i];
    sort(A,A+n);

    while(m--){
        int q,chk=0;
        cin >> q;
        int l=0,r=n-1,mid;
        while(l<=r){
            mid=((l+r)/2);
            if(A[mid]==q){
                chk=1;
                break;
            }
            else if(A[mid]<q)l=mid+1;
            else r=mid-1;
        }
        chk?cout << "YES" << endll:cout << "NO" << endll;
    }

    return 0;
}