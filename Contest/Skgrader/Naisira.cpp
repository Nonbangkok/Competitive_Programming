#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int n,mx=-1;
    cin >> n;
    int A[n+1];
    forr(i,1,n+1){
        cin >> A[i];
        // A[i] *= 2;
        mx = max(mx,A[i]);
    }

    // forr(i,1,mx*2+1){
    for(int i=mx*2;i>0;i--){
        forr(j,1,n+1){
            if(i<=A[j]*2)cout << "####";
            else cout << "    ";
            cout << "  ";
        }
        cout << endll;
    }




    return 0;
}