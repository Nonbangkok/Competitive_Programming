#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    bool first = true, chk = true;
    int n,result,sum = 0;
    cin >> n;
    int a[n][n],num[n*n+1];
    memset(num,0,sizeof(num));
    forr(i,0,n)forr(j,0,n)cin >> a[i][j],num[a[i][j]]=1;

    forr(i,1,n*n+1){
        if(num[i]==1)continue;
        cout << "No";
        return 0;
    }

    forr(i,0,n){
        forr(j,0,n)sum+=a[i][j];
        if(first)result = sum,first=false;
        else if(sum != result)chk=false;
        sum = 0;
    }

    forr(i,0,n){
        forr(j,0,n)sum += a[j][i];
        if(sum != result)chk=false;
        sum = 0;
    }

    forr(i,0,n)sum += a[i][i];
    if(sum != result)chk=false;
    sum = 0;

    forr(i,0,n)sum += a[i][n-i-1];
    if(sum != result)chk=false;
    sum = 0;

    cout << (chk?"Yes":"No");

    return 0;
}