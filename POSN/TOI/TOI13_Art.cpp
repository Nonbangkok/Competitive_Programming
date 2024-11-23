#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+1;

struct Non{
    int pos,high,color;

    bool operator <(const Non &rhs)const{
        return pos<rhs.pos;
    }
};

vector<Non> A;
int fw[N];

void update(int idx,int val){
    for(int i=idx;i<=N;i+=(i&-i))fw[i]+=val;
}

int query(int idx){
    int sum=0;
    for(int i=idx;i>0;i-=(i&-i))sum+=fw[i];
    return sum;
}

int find(int t){
    int l=1,r=N,m;

    while(l<r){
        m=(l+r)>>1;

        if(query(m)<=t)r=m;
        else l=m+1;
    }
    return l;
}

int main(){macos;

    int n,t;
    cin >> n >> t;
    forr(i,0,n){
        int s,h,w,o;
        cin >> s >> h >> w >> o;
        A.push_back({s,h,o});
        A.push_back({s+w,h,-o});
    }
    sort(A.begin(),A.end());

    int ans=0,prev=0;
    for(auto [x,h,o]:A){
        ans+=(x-prev)*(find(t-1)-find(t));
        prev=x;
        update(1,o);
        update(h+1,-o);
    }
    cout << ans;

    return 0;
}