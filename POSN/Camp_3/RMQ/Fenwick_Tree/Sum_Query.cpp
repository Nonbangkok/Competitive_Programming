#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+10;
int fw[N];

void update(int idx,int val){
    for(int i=idx;i<100;i+=(i&-i))fw[i]+=val;
}

int query(int idx){
    int sum=0;
    for(int i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int main(){macos;

    forr(i,0,10)update(i+1,i+1);
    cout << query(5) << endll;

    return 0;
}