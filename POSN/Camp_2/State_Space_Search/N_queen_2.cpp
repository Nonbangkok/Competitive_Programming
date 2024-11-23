#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//DFS+Backtracking
int n,cnt;
bool isValid(int *A,int k){
    forr(i,1,k){
        if(A[i]==A[k]||abs(A[i]-A[k])==k-i)return false;
    }
    return true;
}

void sSolve(int *A,int m){
    if(m==n+1){
        cout << '[';
        forr(i,1,n+1)cout << A[i] << sp;
        cout << ']' << endll;
        cnt=0;
    }else{
        forr(i,1,n+1){
            A[m]=i;
            if(isValid(A,m))sSolve(A,m+1);
        }
    }
}

int main() {macos;

    int t;
    cin >>t;
    while(t--){   
        cin >> n;
        int N[n+2];
        cnt=1;
        sSolve(N,1);
        if(cnt){
            cout << "-1" << endll;
        }
    }

    return 0;
 }