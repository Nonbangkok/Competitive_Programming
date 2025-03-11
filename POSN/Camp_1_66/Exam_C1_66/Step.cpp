#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5010;
int A[N],B[N];
int n,ans = 1e9, zero = 0,mn = 1e9;

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> A[i],mn = min(mn,A[i]);
    forr(i,0,n){
        cin >> B[i];
        if(B[i]==0&&A[i]!=mn)zero = 1;
    }

    if(zero){
        cout << -1;
        return 0;
    }
    
    forr(i,0,5001){
        int cnt = 0;
        bool chk = 1;
        forr(j,0,n){
            if(B[j]==0)continue;
            if((A[j]-i)%B[j]||(A[j]-i)/B[j]<0){
                chk = 0;
                break;
            }
            cnt += (A[j]-i)/B[j];
        }
        if(chk)ans = min(ans,cnt);
    }
    cout << (ans!=1e9?ans:-1);

    return 0;
}