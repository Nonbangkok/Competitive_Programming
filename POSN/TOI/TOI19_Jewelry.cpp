#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

stack<pair<int,int>> st;
ll ans,sum,n,l;
string s;

int main(){macos;

    cin >> n >> s;
    forr(i,0,n){
        if(s[i]=='T'){
            l++;
            while(!st.empty()&&st.top().second<l)st.pop();
            if(!st.empty())sum += i - st.top().first + l - 1;
            else sum += i + 1;
            st.push({i,l});
        }else l = 0;
        ans += sum;
    }

    cout << ans;

    return 0;
}