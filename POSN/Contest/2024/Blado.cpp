#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    vector<ll> price,product;
    unordered_map<string,ll> mp;

    ll n,m,tmp;
    cin >> n >> m;
    forr(i,0,n){cin >> tmp;price.push_back(tmp);}

    string s;
    forr(i,0,m){cin >> s;mp[s]++;}

    for(auto i:mp)product.push_back(i.second);

    sort(price.begin(),price.end());
    sort(product.begin(),product.end(),greater<int>());

    ll sum=0;
    forr(i,0,m)sum+=price[i]*product[i];
    cout << sum << sp;

    sum=0;
    reverse(price.begin(),price.end());
    forr(i,0,m)sum+=price[i]*product[i];
    cout << sum;

    // for(auto i : price)cout << i << sp;cout << endll;
    // for(auto i : product)cout << i << sp;cout << endll;

    return 0;
}