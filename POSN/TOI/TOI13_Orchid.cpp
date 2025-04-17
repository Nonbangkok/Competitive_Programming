#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,x;
vector<int> lis;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> x;
        auto idx = upper_bound(lis.begin(),lis.end(),x);
        if(idx==lis.end())lis.push_back(x);
        else *idx = x;
    }

    cout << n - lis.size();

    return 0;
}