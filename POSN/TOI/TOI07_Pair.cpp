#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int a,b;

    bool operator < (const Non &rhs)const{
        return b<rhs.b;
    }
};

int main() {macos;

    int n,a,b;
    cin >> n;
    vector<Non> A;
    forr(i,0,n){
        cin >> a >> b;
        A.push_back({a,b});
    }
    sort(A.begin(),A.end());

    ll sum=0;
    forr(i,0,n){
        forr(j,i,n){
            if(A[i].a>A[j].a){
                sum+=A[i].a+A[j].a;
            }
        }
    }
    cout << sum;

    return 0;
}