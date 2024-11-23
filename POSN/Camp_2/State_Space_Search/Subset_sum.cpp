#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[1000],n,k,cnt=0,sum;
//vector<int> S;

void Ssol(int i,int sum){
    if(i==n){
        if(sum==k)cnt++;
    }else{
        //S.push_back(0);
        Ssol(i+1,sum);
        //S.pop_back();
        if(sum+A[i+1]<=k){//backtracking
            //S.push_back(1);
            Ssol(i+1,sum+A[i+1]);
            //S.pop_back();
        }
    }
}
//include backtracking by add parameter named sum to collect sum in each state


int main() {macos;

    cin >> n;
    forr(i,0,n){
        cin >> A[i];
    }
    cin >> k;
    Ssol(0,0);
    cout << cnt;

    return 0;
 }
