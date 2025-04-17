#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setpcision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1010;
int n,x;
int a[N],p[N];
vector<int> lis,idxs,res;

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> a[i],p[i] = -1;

    forr(i,0,n){
        auto it = lower_bound(lis.begin(),lis.end(),a[i]);
        int idx = it - lis.begin();
        if(it==lis.end())lis.push_back(a[i]),idxs.push_back(i);
        else *it = a[i],idxs[idx] = i;
        if(idx)p[i] = idxs[idx-1];
    }

    int cur = idxs.back();
    while(cur!=-1)res.push_back(a[cur]),cur = p[cur];
    reverse(res.begin(),res.end());
    for(int i:res)cout << i << sp;

    return 0;
}