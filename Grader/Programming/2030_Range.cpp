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
int n,p,q,l;
ll ans;
int a[N];
deque<int> mn,mx;

int main(){macos;

    cin >> n >> p >> q;
    forr(i,1,n+1)cin >> a[i];

    l = 0;
    forr(i,1,n+1){
        while(!mn.empty()&&a[mn.back()]>=a[i])mn.pop_back();
        while(!mx.empty()&&a[mx.back()]<=a[i])mx.pop_back();
        mn.push_back(i);mx.push_back(i);
        while(!mn.empty()&&!mx.empty()&&a[mx.front()]-a[mn.front()]>q){
            if(mn.front()>mx.front())l = mx.front(),mx.pop_front();
            else l = mn.front(),mn.pop_front();
        }
        ans += i - l;
    }
    while(!mn.empty())mn.pop_back();
    while(!mx.empty())mx.pop_back();
    l = 0;
    forr(i,1,n+1){
        while(!mn.empty()&&a[mn.back()]>=a[i])mn.pop_back();
        while(!mx.empty()&&a[mx.back()]<=a[i])mx.pop_back();
        mn.push_back(i);mx.push_back(i);
        while(!mn.empty()&&!mx.empty()&&a[mx.front()]-a[mn.front()]>p-1){
            if(mn.front()>mx.front())l = mx.front(),mx.pop_front();
            else l = mn.front(),mn.pop_front();
        }
        ans -= i - l;
    }
    cout << ans;

    return 0;
}