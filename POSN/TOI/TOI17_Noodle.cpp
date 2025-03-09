#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e5+10;
ll A[N];
ll n,m,k;
priority_queue<ll,vector<ll>,greater<ll>> q;

int main(){macos;

    cin >> n >> m >> k;
    forr(i,0,n)cin >> A[i];

    ll l = 0,mid,r = 1e18;
    while(l<r){
    
        mid = (l+r) >> 1;

        ll cnt = 0, sum = 0;
        forr(i,0,n){
            sum += A[i];
            q.push(A[i]);
            if(q.size()>k){
                sum -= q.top();
                q.pop();
            }
            if(q.size()==k&&sum>=mid){
                sum = 0;
                cnt++;
                while(!q.empty())q.pop();
            }
        }
        while(!q.empty())q.pop();

        if(cnt>=m)l = mid + 1;
        else r = mid;
    }
    cout << l-1;

    return 0;
}