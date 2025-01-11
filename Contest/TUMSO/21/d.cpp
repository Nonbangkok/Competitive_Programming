#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (ll i = a; i < n; i++)
#define forl(i, a, n) for (ll i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<pair<ll,ll>> v;
priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > q;

int main(){macos;

    ll n,cnt = 0;
    cin >> n;
    ll minl = INT_MAX, maxr = INT_MIN,a,b;
    forr(i,0,n){
        cin >> a >> b;
        minl = min(minl,a);
        maxr = max(maxr,b);
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),greater<pair<ll,ll>>());

    forr(i,minl,maxr+1){
        while(!q.empty() && q.top().first<i)q.pop();
        if(q.empty())i = v.back().first;
        while(!v.empty() && v.back().first == i){
            q.push({v.back().second,v.back().second-v.back().first});
            v.pop_back();
        }
        if(q.empty())break;
        q.pop();
        cnt++;
    }

    cout << cnt;

    return 0;
}