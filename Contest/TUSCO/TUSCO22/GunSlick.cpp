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

    int n,a,b,sum=0,ans=INT_MIN;
    vector<pair<int,int>> A;
    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        A.push_back({a,1});
        A.push_back({b,0});
    }
    sort(A.begin(),A.end());
    forr(i,0,A.size()){
        if(A[i].second)sum++;
        else sum--;
        ans=max(ans,sum);
    }
    cout << ans;

    return 0;
}