#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e6+10;
int a[N];
int main(){macos;

    stack<int> st;
    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int mx=-1,area=0;
        forr(i,0,n){
            cin >> a[i];
            while(!st.empty()&&a[st.top()]>a[i]){
                int top=st.top();
                st.pop();
                if(st.empty())area=a[top]*i;
                else area=a[top]*(i-st.top()-1);
                mx=max(mx,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(st.empty())area=a[top]*n;
            else area=a[top]*(n-st.top()-1);
            mx=max(mx,area);
        }

        cout << mx << endll;
    }

    return 0;
}