#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,k,cnt=0;

void sSearch(int i,int chk,int cnt0){
    if(i==n)cnt++;
    else{
        sSearch(i+1,1,cnt0);
        if(cnt0<=k-1&&chk)sSearch(i+1,0,cnt0+1);
    }
}

int main() {macos;

    cin >> n >> k;
    sSearch(0,1,0);
    cout << cnt;

    return 0;
}