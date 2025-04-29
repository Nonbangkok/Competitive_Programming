#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
int n,k,a,b,c,d,pre,ans;
vector<tuple<int,int,int>> event;

struct Fenwick{
    int fw[N];

    Fenwick(){
        forr(i,0,N)fw[i] = 0;
    }

    void update(int idx, int val){
        for(int i=idx;i<N;i+=i&-i)fw[i] += val;
    }

    int query(int idx){
        int sum = 0;
        for(int i=idx;i>0;i-=i&-i)sum += fw[i];
        return sum;
    }

    int find(int t){
        int l = 1, r = N-1, m;
        while(l<r){
            m = (l+r) >> 1;
            if(query(m)>t)l = m + 1;
            else r = m;
        }
        return l;
    }
}fw;

int main(){macos;

    cin >> n >> k;
    forr(i,0,n){
        cin >> a >> b >> c >> d;
        event.push_back({a,b,d});
        event.push_back({a+c,b,-d});
    }

    sort(event.begin(),event.end());

    for(auto[x,h,o]:event){
        ans += (x-pre)*(fw.find(k-1)-fw.find(k));
        pre = x;
        fw.update(1,o);
        fw.update(h+1,-o);
    }
    
    cout << ans;

    return 0;
}