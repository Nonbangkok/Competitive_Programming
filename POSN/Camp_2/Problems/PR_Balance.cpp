#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,tmp;
    cin >> n;
    while(n--){
        int neg=0;
        vector<int> ans;
        cin >> tmp;
        if(tmp<0){tmp*=-1;neg=1;}
        while(tmp){
            if(tmp%3==2){
                tmp++;
                ans.push_back(-1);
            }else ans.push_back(tmp%3);
            tmp/=3;
        }
        reverse(ans.begin(),ans.end());
        for(auto i : ans)if(neg)cout << -i << sp;else cout << i << sp;cout << endll;
    }

    return 0;
}