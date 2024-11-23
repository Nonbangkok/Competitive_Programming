#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define int long long 
using namespace std;

int n,l,a,b;
multiset<int> le,mid,r;

void balance(){
    while(r.size()>n-b){
        int temp = *r.begin();
        r.erase(r.begin());
        mid.insert(temp);
    }
    while(mid.size()>b-a){
        int temp = *mid.begin();
        mid.erase(mid.begin());
        le.insert(temp);
    }
    while(!mid.empty()&&!r.empty()&&*(--mid.end())>*r.begin()){
        int temp1 = *r.begin();
        int temp2 = *(--mid.end());
        mid.erase(--mid.end());
        r.erase(r.begin());
        mid.insert(temp1);
        r.insert(temp2);
    }
    while(!le.empty()&&!mid.empty()&&*(--le.end())>*mid.begin()){
        int temp1 = *mid.begin();
        int temp2 = *(--le.end());
        le.erase(--le.end());
        mid.erase(mid.begin());
        le.insert(temp1);
        mid.insert(temp2);
    }
}

int32_t main(){macos;

    cin >> n >> l >> a >> b;
    a--;b--;
    forr(i,0,n){
        int temp;
        cin >> temp;
        r.insert(temp);
    }
    balance();
    forr(i,0,l){
        int x = *mid.begin(), y = *r.begin();
        mid.erase(mid.begin());
        r.erase(r.begin());
        r.insert(y-x);
        r.insert((x+y)>>1);
        balance();
    }
    for(int i:le)cout << i << sp;
    for(int i:mid)cout << i << sp;
    for(int i:r)cout << i << sp;

    return 0;
}