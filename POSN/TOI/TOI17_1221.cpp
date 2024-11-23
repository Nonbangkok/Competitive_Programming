#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m,q,a,b,c;
    cin >> n >> m >> q;
    int A[n],dis[n][n],cnt[n][n];
    forr(i,0,n)cin >> A[i];
    forr(i,0,n)forr(j,0,n){
        if(i==j)dis[i][j]=0,cnt[i][j]=0;
        else dis[i][j]=A[i]+A[j],cnt[i][j]=2;
        }
    forr(i,0,m){
        cin >> a >> b >> c;
        a--;b--;
        dis[a][b]=c;dis[b][a]=c;
        cnt[a][b]=2;cnt[b][a]=2;
    }
    forr(k,0,n)forr(j,0,n)forr(i,0,n){
        if(dis[i][j]>dis[i][k]+dis[k][j]){
            dis[i][j]=dis[i][k]+dis[k][j];
            cnt[i][j]=cnt[i][k]+cnt[k][j];
            //cout << i+1 << sp << k+1 << sp << j+1 << sp << dis[i][j] << sp << cnt[i][j] << endll;
        }else if(dis[i][j]==dis[i][k]+dis[k][j])cnt[i][j]=max(cnt[i][j],cnt[i][k]+cnt[k][j]);
    }
    forr(i,0,q){
        cin >> a >> b;
        a--;b--;
        cout << dis[a][b] << sp << cnt[a][b] << endll;
    }


    return 0;
}