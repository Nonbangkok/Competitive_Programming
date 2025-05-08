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
int a[N];
stack<int> st;

int main(){macos;

    cin >> n;
    forr(i,1,n+1){
        cin >> a[i];
        while(!st.empty()&&a[st.top()]>=a[i])st.pop();
        if(!st.empty())cout << st.top() << sp;
        else cout << 0 << sp;
        st.push(i);
    }

    return 0;
}