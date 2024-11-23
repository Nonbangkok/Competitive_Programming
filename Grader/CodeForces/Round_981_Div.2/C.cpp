#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2e5+10;
int A[N];
int main(){macos;

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        forr(i,1,n+1)cin >> A[i];
        forr(i,1,n){
            if(A[i]==A[i+1]&&A[i]!=A[n-i+2]){
                // cout << "Pass ";
                int temp = A[i];
                A[i] = A[n-i+1];
                A[n-i+1] = temp;
            }
            // forr(i,1,n+1)cout << A[i] << sp;cout << endll;
        }
        forr(i,1,n){
            if(A[i]==A[i+1]&&A[i]!=A[n-i+2]){
                // cout << "Pass ";
                int temp = A[i];
                A[i] = A[n-i+1];
                A[n-i+1] = temp;
            }
            // forr(i,1,n+1)cout << A[i] << sp;cout << endll;
        }
        ll cnt = 0;
        forr(i,1,n)cnt += (A[i]==A[i+1]);
        cout << cnt << endll;
    }

    return 0;
}