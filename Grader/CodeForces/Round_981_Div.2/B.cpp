#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 2001;
int A[N];
int main(){macos;

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        forr(i,0,(n-1)*2+1)A[i] = INT_MAX;
        forr(i,0,n){
            forr(j,0,n){
                int temp;
                cin >> temp;
                A[i-j+(n-1)] = min(A[i-j+(n-1)],temp);
            }
        }
        ll sum = 0;
        forr(i,0,(n-1)*2+1){
            if(A[i]<0)sum+=A[i];
            // cout << A[i] << sp;
        }
        // cout << endll;
        cout << -sum << endll;
    }


    return 0;
}