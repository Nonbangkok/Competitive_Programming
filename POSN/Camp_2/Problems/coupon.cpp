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

    int n,m;
    cin >> n >> m;
    int A[n];
    forr(i,0,n)cin >> A[i];
    sort(A,A+n);
    
    int sum,mx=-1;
    vector<int> ans(3);
    forr(i,0,n){
        forr(j,i+1,n){
            forr(k,j+1,n){
                //cout << i << sp << j << sp << k << endll;
                sum=A[i]+A[j]+A[k];
                if(sum>mx&&sum<=m){
                    mx=sum;
                    ans={A[i],A[j],A[k]};
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans)cout << i << endll;


    return 0;
 }
