#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int par[200000],cnt[200000];
int findpar(int x){
    if(x!=par[x])par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    int n,q;
    cin >> n >> q;
    forr(i,0,n)par[i]=i;

    forr(i,0,q){
        int a,b;
        cin >> a >> b;
        par[findpar(b)]=par[findpar(a)];
    }
    //forr(i,0,n)cout << par[i] << sp;
    forr(i,0,n)cnt[par[findpar(i)]]++;

    sort(cnt,cnt+n,greater<int>());

    vector<int> ans;
    int c=0;
    forr(i,0,n){
        if(cnt[i]==0)break;
        c++;
        ans.push_back(cnt[i]);
    }
    cout << c << endll;
    for(auto i:ans)cout << i << sp;

    return 0;
}