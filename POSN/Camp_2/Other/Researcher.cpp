#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e4+10;
int dp[N],A[N],n;

int greedy(int x){
    int ans = 0;
    int i = upper_bound(A,A+n,x)-A-1;
    while(x){
        while(x-A[i]>=0){
            x -= A[i];
            ans++;
        }
        i--;
    }
    return ans;
}

int dynamics(int x){
    dp[0]=0;
    forr(i,1,x+1){
        dp[i]=1e9;
        forr(j,0,n){
           if(i>=A[j])dp[i]=min(dp[i],1+dp[i-A[j]]); 
        }
    }
    return dp[x];
}

bool compare(){
    int number = 1000;
    forr(i,1,number+1)if(greedy(i)!=dynamics(i))return 0;
    return 1;
}

int main() {macos;

    cin >> n;
    forr(i,0,n-1)cin >> A[i];

    forr(i,33,65){
        A[n-1] = i;
        if(compare())cout << i << " Can solve by greedy";
        else cout << i << " Can't solve by greedy";
        cout << endll;
    }

    // if(compare())cout << "Can solve by greedy";
    // else cout << "Can't solve by greedy";

    return 0;
 }