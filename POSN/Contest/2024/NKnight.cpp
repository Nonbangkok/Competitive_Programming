#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,mx=-1,A[11][11],c[11],dia[11][11];
int di[]={-2,-1,1,2};
int dj[]={1,2,2,1};

void sSearch(int r,int sum){
    if(r==n)mx=max(mx,sum);
    else{
        forr(i,0,n){
            if(c[i]||dia[r][i])continue;

            c[i]=1;
            forr(k,0,4){
                int dr=r+dj[k];
                int dc=i+di[k];
                if(dr<0||dr>=n||dc>=n)continue;
                dia[dr][dc]=1;
            }

            sSearch(r+1,sum+A[r][i]);

            c[i]=0;
            forr(k,0,4){
                int dr=r+dj[k];
                int dc=i+di[k];
                if(dr<0||dr>=n||dc>=n)continue;
                dia[dr][dc]=0;
            }
        }
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n)forr(j,0,n)cin >> A[i][j];
    sSearch(0,0);
    cout << mx;

    return 0;
}