#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    double sum=0,B[]={1,0.75,0.5,0.25,0.125};
    int n,temp,A[5];
    memset(A,0,sizeof(A));
    cin >> n;
    forr(i,0,n)forr(j,0,5){
        cin >> temp;
        A[j]+=temp;
    }
    forr(i,0,5)sum+=double(A[i])*B[i];
    cout << ceil(sum);

    return 0;
}