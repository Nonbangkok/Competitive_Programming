#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=100;
int A[N][N],n,m,ans=INT_MAX;
//vector<int> v;

void sSearch(int i,int j,int sum){
    if(j==n-1){
        sum+=A[i][j];
        // for(auto k:v) cout << k << sp;
        // cout << endll;
        // cout << i << sp << j << sp << sum << endll;
        // cout << endll;
        ans=min(ans,sum);
    }else{
        if(j+1<=n-1&&sum<=ans){
            //v.push_back(0);
            sSearch(i,j+1,sum+A[i][j]);
            //v.pop_back();
            if(i==m-1){
                //v.push_back(1);
                sSearch(0,j+1,sum+A[i][j]);
                //v.pop_back();
            }else{
                //v.push_back(1);
                sSearch(i+1,j+1,sum+A[i][j]);
                //v.pop_back();
            }
        }
    }
}

int main() {macos;

    cin >> n >> m;
    forr(i,0,m){
        forr(j,0,n){
            cin >> A[i][j];
        }
    }
    forr(i,0,m)sSearch(i,0,0);
    cout << ans;

    return 0;
}