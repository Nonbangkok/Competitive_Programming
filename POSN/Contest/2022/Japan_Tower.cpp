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
int A[N],fw[N],n;

void update(int idx){
    for(int i=idx;i<=N;i+=(i&-i))fw[i]++;
}

int query(int idx){
    int sum=0;
    for(int i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int main(){macos;

    cin >> n;
    forr(i,1,n+1){
        cin >> A[i];
        cout << query(A[i]) << sp;
        update(A[i]);
    }

    return 0;
}