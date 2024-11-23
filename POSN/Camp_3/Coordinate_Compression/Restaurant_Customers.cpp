#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Cses 1619
int main(){macos;

    vector<pair<int,int>> A;
    int n;
    cin >> n;
    
    forr(i,0,n){
        int a,b;
        cin >> a >> b;

        A.push_back({a,1});
        A.push_back({b,-1});
    }
    sort(A.begin(),A.end());

    int cnt=0,mx=INT_MIN;
    forr(i,0,A.size()){
        cnt+=A[i].second;
        mx=max(mx,cnt);
    }
    cout << mx;

    return 0;
}