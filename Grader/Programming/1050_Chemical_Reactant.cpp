#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,p;
map<vector<int>,int> mp;

int main(){macos;

    cin >> n >> p;
    forr(i,0,n){
        vector<int> tmp(p);
        for(int &x:tmp)cin >> x;
        mp[tmp] = i + 1;
    }

    vector<int> des(p);
    for(int &x:des)cin >> x;

    if(mp.find(des)!=mp.end()){
        cout << mp[des];
        return 0;
    }

    for(auto &[v,idx]:mp){
        vector<int> res(p);
        forr(i,0,p)res[i] = des[i] - v[i];
        if(mp.find(res)==mp.end()||mp.find(res)->second==idx)continue;
        cout << min(idx,mp.find(res)->second) << sp << max(idx,mp.find(res)->second);
        return 0;
    }

    cout << "NO";

    return 0;
}