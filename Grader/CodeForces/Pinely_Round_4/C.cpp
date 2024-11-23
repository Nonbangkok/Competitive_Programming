#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int t;
    cin >> t;
    
    while(t--){
        int n,tmp;
        bool even=false,odd=false;
        cin >> n;
        forr(i,0,n){
            cin >> tmp;
            if(tmp&1)odd=true;
            else even=true;
        }
        if(odd&&even)cout << -1;
        else{
            vector<int> ans;
            forl(i,29,-1)ans.push_back(1<<i);
            if(even)ans.push_back(1);
            cout << ans.size() << endll;
            for(int i:ans)cout << i << sp;
        }
        cout << endll;
    }

    return 0;
}