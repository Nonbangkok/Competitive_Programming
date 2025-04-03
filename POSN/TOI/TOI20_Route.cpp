#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<pair<int,int>> route(int N, vector<int> W){
    int n = N, m = W.size();
    vector<pair<int,int>> ans(m);
    
    int i = 2,j = 1,idx = 0;
    while(m>idx&&m-idx>n-i){
        ans[idx++] = {j--,i};
        if(!j)i++,j=i-1;
    }
    forr(k,i,n)ans[idx++] = {k,k+1};
    return ans;
}