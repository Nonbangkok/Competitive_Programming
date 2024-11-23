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

    int n,m,ix,temp;
    cin >> n >> m;
    vector<int> A;
    forr(i,0,n){
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(),A.end());
    forr(i,0,m){
        cin >> ix;
        int upb = lower_bound(A.begin(),A.end(),ix)-A.begin();
        cout << upb << endll;
    }
    //problem have a mistakes
    return 0;
 }