#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll n;
set<ll,greater<ll>> ans;
string s;

void solve(ll i,string temp = ""){
    ll num=0;
    forr(j,0,temp.size())num = (num * 10) + temp[j] - '0';
    ans.insert(num);
    if(i<n)forr(j,i+1,n)solve(j,temp+s[j]);
}

int main(){macos;

    cin >> n >> s;
    solve(-1);
    for(auto i:ans)cout << i << endll;

    return 0;
}