#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=11,M=1e7+10;
ll L[N],dp[M];
int A[N],T[N],Q[N];
int main(){macos;

    bool chk;
    int n,m,x;
    cin >> n >> m >> x;

    forr(i,1,n+1)cin >> L[i];
    forr(i,1,n+1)cin >> A[i];
    forr(i,1,m+1)cin >> dp[i],dp[i]+=dp[i-1];
    forr(i,1,x+1)cin >> T[i];
    sort(L+1,L+n+1);

    forr(t,1,x+1){
        forr(i,1,n+1)cin >> Q[i];Q[n+1]=m;
        
        do{
            chk=true;
            forr(i,1,n+1){
                int l=Q[i],r=Q[i+1],cnt=0;
                while(l<r){
                    int idx=upper_bound(dp+l,dp+r,L[i]+dp[l-1]-A[i])-dp;
                    cnt++;
                    if(cnt>T[t]||idx==l){
                        chk=false;
                        break;
                    }
                    l=idx;
                }
                if(!chk)break;
            }
        }while(!chk&&next_permutation(A+1,A+n+1));
        cout << (chk?"P\n":"F\n");
    }

    return 0;
}