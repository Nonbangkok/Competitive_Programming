#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 40;
bool table[N][N];
int di[]={0,1,0,-1};
int dj0[]={1,0,-1,0},dj1[]={-1,0,1,0};

int main(){macos;

    int n,i,j,l,t;
    char ch;
    cin >> n >> j >> i >> l >> t >> ch;

    for(int k=0;k<l;k++){
        for(int p=1;p<=k+1;p++){
            if(i>=0&&j>=0&&i<n&&j<n)table[i][j] = true;
            i+=di[k%4];
            j+=(t?dj1[k%4]:dj0[k%4]);
        }
    }

    forr(i,0,n){
        forr(j,0,n)cout << (table[i][j]?ch:'.');
        cout << endll;
    }

    return 0;
}