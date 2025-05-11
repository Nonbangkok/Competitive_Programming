#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,q,cmd,k,x;

struct Segment{
    int seg[4*N];
    
    void update(int idx, int val){
        idx += n;
        seg[idx] = val;
        for(int i=idx>>1;i>=1;i>>=1)seg[i] = min(seg[i<<1],seg[(i<<1)+1]);
    }

    int query(int a, int b){
        int ans = 1e9;
        for(a+=n,b+=n;a<=b;a>>=1,b>>=1){
            if(a&1)ans = min(ans,seg[a++]);
            if(!(b&1))ans = min(ans,seg[b--]);
        }
        return ans;
    }
    
}seg1,seg2;

int main(){macos;

    cin >> n >> q;
    forr(i,1,n+1)cin >> x,seg1.update(i,x-i),seg2.update(i,x+i);
    while(q--){
        cin >> cmd;
        if(cmd==1){
            cin >> k >> x;
            seg1.update(k,x-k),seg2.update(k,x+k);
        }else{
            cin >> k;
            cout << min(seg1.query(1,k)+k,seg2.query(k+1,n)-k) << endll;
        }
    }

    return 0;
}