#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=301,K=601;
char ch;
int tr[K],tl[K];
int main(){macos;

    int n,m,k;
    cin >> n >> m >> k;


    forr(i,1,n+1){
        forr(j,1,m+1){
            cin >> ch;
            tr[i+j-2]+=(ch=='#');
            tl[i+m-j-1]+=(ch=='#');
        }
    }
    forr(i,1,K+1)tr[i]+=tr[i-1];
    forr(i,1,K+1)tl[i]+=tl[i-1];

    //forr(i,0,n+m)cout << tr[i] << sp;cout << endll;
    //forr(i,0,n+m)cout << tl[i] << sp;cout << endll;

    return 0;
}