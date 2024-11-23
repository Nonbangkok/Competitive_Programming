#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e4+5001,K=5001;
int fw[N][N];

void update(int a,int b){
    for(int i=a;i<N;i+=(i&-i))for(int j=b;j>0;j-=(j&-j))fw[i][j]++;
}

int query(int a,int b){
    int sum=0;
    for(int i=a;i>0;i-=(i&-i))for(int j=b;j<N;j+=(j&-j))sum+=fw[i][j];
    return sum;
}

int main(){macos;

    int n,x,h;
    cin >> n;
    forr(i,0,n){
        cin >> x >> h;
        cout << query(K+x-h,K+x+h) << endll;
        update(K+x-h,K+x+h);
    }

    return 0;
}