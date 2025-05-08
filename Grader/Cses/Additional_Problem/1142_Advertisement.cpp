#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n;
ll a[N],mx;
stack<int> st;

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> a[i];
    forr(i,0,n+1){
        while(!st.empty()&&a[st.top()]>=a[i]){
            int j = st.top();
            st.pop();
            if(st.empty())mx = max(mx,i*a[j]);
            else mx = max(mx,(i-st.top()-1)*a[j]);
        }
        st.push(i);
    }

    cout << mx;

    return 0;
}