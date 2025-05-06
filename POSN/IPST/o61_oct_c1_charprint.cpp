#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2 * 3e5 + 10;
ll mode,ans,pos;
bool chk;
string a,b;
queue<int> q[26];

struct Fenwick{
    ll fw[N];

    Fenwick(){
        forr(i,0,N)fw[i] = 0;
    }

    void update(ll idx, ll val){
        idx++;
        for(ll i=idx;i<N;i+=i&-i)fw[i] += val;
    }

    ll query(ll idx){
        idx++;
        ll sum = 0;
        for(ll i=idx;i>0;i-=i&-i)sum += fw[i];
        return sum;
    }
}fw;

int main(){macos;

    cin >> mode >> a >> b;
    forr(i,0,a.size())q[a[i]-'a'].push(i);
    forr(i,0,b.size()){
        pos = b[i] - 'a';
        if(!q[pos].empty()){
            ans += q[pos].front() - fw.query(q[pos].front()) + 1;
            if(mode)fw.update(q[pos].front(),1);
            q[pos].pop();
        }else{chk = true;break;}
    }

    cout << (chk?-1:ans);

    return 0;
}