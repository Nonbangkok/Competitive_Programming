#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int t,n;
int A[11];
bool chk;

bool is_valid(int i){
    forr(j,1,i)if(A[i]==A[j]||i-j==abs(A[i]-A[j]))return false;
    return true;
}

void solve(int i){
    if(i==n+1){
        cout << '[';
        forr(j,1,n+1)cout << A[j] << sp;
        cout << ']' << sp;
        chk = false;
    }else{
        forr(j,1,n+1){
            A[i] = j;
            if(!is_valid(i))continue;
            solve(i+1);
        }
    }
}

int main(){macos;

    cin >> t;

    while(t--){
        cin >> n;
        chk = true;
        solve(1);
        if(chk)cout << -1; 
        cout << endll;
    }

    return 0;
}