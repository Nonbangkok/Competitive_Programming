#include <bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define macos ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define sp ' '
#define endll "\n"
using namespace std;

const int N = 1e6 + 10;
ll n,l,sum,ans;
string s;
stack<pair<ll,ll>> st;

int main(){macos;

    cin >> n >> s;
    forr(i,0,n){
        if(s[i]=='F')l = 0;
        else{
            l++;
            while(!st.empty()&&st.top().second<l)st.pop();
            if(st.empty())sum += i + 1;
            else sum += i - st.top().first + (l - 1);
            // else sum += i - (st.top().first - l + 1);
            st.push({i,l});
        }
        ans += sum;
    }
    cout << ans;

    return 0;
}