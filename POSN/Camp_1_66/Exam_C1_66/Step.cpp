#include <iostream>
#include <cmath>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
using namespace std;
int main() {macos;

    int n,ai=5001,b;
    cin >> n;
    int A[n];

    forr(i,0,n){
        cin >> A[i];
        ai=min(ai,A[i]);
    }

    int ans=0;
    forr(i,0,n){
        cin >> b;
        if(A[i]>=b&&(A[i]-ai)/b==ceil((A[i]-ai)/b)){
            ans+=(A[i]-ai)/b;
            //cout << (A[i]-ai)/b << sp;
        }
    }
    (ans==0)? cout << -1 : cout << ans;

    return 0;
 }
