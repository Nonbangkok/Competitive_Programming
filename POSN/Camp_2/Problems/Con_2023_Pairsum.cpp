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

    int n,k;
    cin >> n >> k;
    int A[n],B[n];
    forr(i,0,n){
        cin >> A[i];
    }
    forr(i,0,n){
        cin >> B[i];
    }
    sort(A,A+n);
    sort(B,B+n,greater<int>());
    int i=0,j=0,sum=0;
    while(1){
        if(i==n||j==n)break;
        if(A[i]+B[j]>k){
            sum++;
            i++;
            j++;
        }else{
            i++;
        }
    }
    cout << sum;

    return 0;
 }
