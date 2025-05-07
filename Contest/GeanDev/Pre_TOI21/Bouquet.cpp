#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int n,k;
int a[N];
ll p[N],sum,ans;

template<class T>
using pq = priority_queue<T,vector<T>,greater<T>>;
pq<tuple<ll,int,int>> q;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> p[i],sum += p[i];
    forr(i,1,n+1){
        cin >> a[i];
        if(a[i]>1)q.push({p[i],1,i});
    }
    ans += sum;k--;
    cout << sum << sp;
    while(k--){
        auto [val,x,idx] = q.top();
        q.pop();
        if(x+1>a[idx])continue;
        q.push({val+p[idx],x+1,idx});
        ans += sum + val;
        cout << sum + val << sp;
    }
    cout << endll;
    cout << ans;
    
    return 0;
}