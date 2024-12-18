#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N =5e5+10;
ll A[N];
vector<pair<ll,ll>> B,C;
vector<int> dp(N,-1);
stack<int> s;
int main(){macos;

    ll sum = 0,n,m;
    cin >> n;
    forr(i,0,n)cin >> A[i];

    for (int i=n-1;i>=0;--i){
        while(!s.empty()&&A[i]<=A[s.top()])s.pop();
        if(!s.empty())dp[i] = s.top();
        s.push(i);
    }

    for (int i = 0; i < n; ++i){
        if (dp[i] != -1) {
            cout << abs(i - dp[i]) << sp;
            sum += abs(i - dp[i]);
        }else cout << 0 << sp;
    }
    cout << endll;

    cin >> m;
    forr(i,0,m){
        ll a,b;
        cin >> a >> b;
        B.push_back({b,a});
    }
    sort(B.begin(),B.end());

    ll mn = LLONG_MAX;
    for(auto i:B){
        mn = min(mn,i.second);
        C.push_back({i.first,mn});
    }

    forr(i,0,n){
    auto it = upper_bound(C.begin(), C.end(), make_pair(A[i], LLONG_MAX))-C.begin()-1;
        cout << C[it].second << sp;
        sum += C[it].second;
    }
    cout << endll << sum;

    return 0;
}