#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
multiset<int> a,b,c;
vector<int> tmp;
int main(){macos;

    int n,m,u,v,x,y;
    cin >> n >> m >> u >> v;
    forr(i,0,n)cin >> x,tmp.push_back(x);
    sort(tmp.begin(),tmp.end());

    forr(i,0,u)a.insert(tmp[i]);
    forr(i,u,v)b.insert(tmp[i]);
    forr(i,v,n)c.insert(tmp[i]);
    while(m--){
        x = *(--a.end());
        y = *(--b.end());
        a.erase(--a.end());
        b.erase(--b.end());
        a.insert((x+y)/2);
        a.insert(y-x);
        if(a.size()>u){
            b.insert(*(--a.end()));
            a.erase(--a.end());
        }
        if(*(--a.end())>*b.begin()){
            x = *(--a.end());
            y = *b.begin();
            a.erase((--a.end()));
            b.erase(b.begin());
            a.insert(y);
            b.insert(x);
        }
    }
    
    for(int i:a)cout << i << sp;
    for(int i:b)cout << i << sp;
    for(int i:c)cout << i << sp;

    return 0;
}