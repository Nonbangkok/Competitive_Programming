#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=6e6+10;
int qs[N];
deque<int> q;
int main(){macos;
    
    int n,w,val,valsz,ans=0,sz=0;
    cin >> n >> w;
    forr(i,1,n+1)cin >> qs[i],qs[i]+=qs[i-1];

    q.push_back(0);
    forr(i,1,n+1){
        while(!q.empty()&&i-q.front()>w)q.pop_front();
        while(!q.empty()&&qs[q.back()]>qs[i])q.pop_back();
        q.push_back(i);
        val=qs[i]-qs[q.front()];
        valsz=i-q.front();
        if(ans<val)ans=val,sz=valsz;
        if(ans==val)sz=min(sz,valsz);
    }
    cout << ans << endll << sz;

    return 0;
}