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

int main() {macos;

    int n;
    ll l=0,sum=0,ans=0;
    string s;
    cin >> n >> s;

    forr(i,0,n){
        if(s[i]=='F')l=0;
        else{
            l++;
            while(!st.empty()&&st.top().first<l)st.pop();
            if(st.empty())sum+=i+1;
            else sum+=(i-st.top().second)+(l-1);
            st.push({l,i});
        }
        ans+=sum;
    }
    cout << ans;

    return 0;
}