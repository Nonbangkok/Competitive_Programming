#include<bits/stdc++.h>
#define int long long

using namespace std;

int t;

void solve(){
    int n, mx = 0, st = 1, ans = 0; cin >> n;
    vector<int> arr(n+10, 0), freq(n+10, 0);
    for(int i = 1; i<=n; ++i) cin >> arr[i], ans+=arr[i];
    for(int i = 1; i<=n; ++i){
        freq[arr[i]]++;
        if(freq[arr[i]] > 1) mx = max(mx, arr[i]);
        arr[i] = mx; 
    }
    vector<int> cnt(n+10, 0);
    mx = 0;
    for(int i = 1; i<=n; ++i){
        cnt[arr[i]]++;
        if(cnt[arr[i]] > 1) mx = max(mx, arr[i]);
        ans+=arr[i];
        ans+=(n - i + 1)*mx;
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t;
    while(t--) solve();
}