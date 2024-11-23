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
int n,t,cnt=1,A[1000],suma=0;

void Ssol(int i,int sum){
    if(i==n){
        if(sum*2==suma&&cnt){
            cout << "YES" << endll;
            cnt=0;
        }
    }else if(cnt){
        if((sum+A[i])*2<=suma){    
            Ssol(i+1,sum+A[i]);
        }
        Ssol(i+1,sum);
    }
}

int main() {macos;

    cin >> t;
    forr(i,0,t){
        cin >> n;
        forr(i,0,n){
            cin >> A[i];
            suma+=A[i];
        }
        if(suma%2==0)Ssol(0,0);
        if(cnt)cout << "NO" << endll;
        cnt=1;
        suma=0;
    }

    return 0;
 }
