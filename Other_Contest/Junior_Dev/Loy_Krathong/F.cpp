#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5010 , M = 10010;
ll A[N];
bool dp[M];
ll sum = 0;

int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n){
        cin >> A[i];
        sum += A[i];
    }

    dp[0] = true;
    forr(i,0,n)for(int j=sum/2;j>=A[i];j--)if(dp[j-A[i]])dp[j] = true;
    
    for(int i=sum/2;i>=0;i--){
        if(dp[i]){
            cout << sum-2*i;
            break;
        }
    }

    return 0;
}