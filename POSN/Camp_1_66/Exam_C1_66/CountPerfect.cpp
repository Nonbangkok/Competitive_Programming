#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    vector<int> A(100001,0);
    for(int i=1;i*i<=100000;i++){
        A[i*i]=1;
    }

    int t,a,b,cnt;
    cin >> t;
    forr(i,0,t){
        cin >> a >> b;
        cnt=0;
        forr(j,a,b+1){
            cnt+=A[j];
        }
        cout << cnt << endll;
    }

    return 0;
 }