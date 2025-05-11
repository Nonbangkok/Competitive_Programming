#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5+10;
int n,q,x;

struct seg{
    long long tree[2*sz];
    void add(int idx,int x){
        idx += n;
        tree[idx] = x;
        for(int i=idx/2;i>=1;i/=2)tree[i] = min(tree[i*2],tree[i*2+1]);
    }

    long long qury(int a,int b){
        long long ans = INT_MAX;
        for(a+=n,b+=n;a<=b;a>>=1,b>>=1){
            if(a&1)ans = min(ans,tree[a++]);
            if(!(b&1))ans = min(ans,tree[b--]);
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    seg t1,t2;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> x;
        t1.add(i,x-i);
        t2.add(i,x+i);
    }
    while (q--){
        int a,b,c;
        cin >> c;
        if(c==1){
            cin >> a >> b;
            t1.add(a,b-a);
            t2.add(a,b+a);
        }else{
            cin >> a;
            cout << min(t1.qury(1,a)+a,t2.qury(a+1,n)-a) << "\n";
        }
    }
    return 0;
}