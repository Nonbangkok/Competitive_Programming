#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int A[16][16],table[16],n;
ll mx=INT_MIN;

bool isValid(int i){
    forr(j,1,i){
        if(table[i]==table[j]||abs(table[i]-table[j])==i-j)return true;
    }
    return false;
}

void sSearch(int i,ll sum){
    if(i==n+1)mx=max(mx,sum);
    else{
        forr(j,1,n+1){
            table[i]=j;
            if(isValid(i))continue;
            sSearch(i+1,sum+A[i][j]);
        }
    }
}

int main() {macos;

    cin >> n;
    forr(i,1,n+1)forr(j,1,n+1)cin >> A[i][j];
    sSearch(1,0);
    cout << mx;

    return 0;
}