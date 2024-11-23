#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
multiset<int> s;
int main(){macos;

    int n,m,u,v,tmp;
    cin >> n >> m >> u >> v;
    forr(i,0,n)cin >> tmp,s.insert(tmp);
    multiset<int>::iterator x,y;

    while(m--){
        x=s.begin(),y=s.begin();
        forr(i,1,u)x++;forr(i,1,v)y++;
        int a=*x,b=*y;
        s.erase(x);s.erase(y);
        s.insert(b-a);s.insert((a+b)>>1);
    }
    for(auto i:s)cout << i << sp;

    return 0;
}