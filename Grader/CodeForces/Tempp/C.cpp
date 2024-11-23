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
        int n;
        char ch;
        cin >> n;
        stack<int> st;
        ll sum = 0;
        forr(i,0,n){
            cin >> ch;
            if(ch == '_'){
                if(st.size()==0)st.push(i);
                else sum += i-st.top(),st.pop();
            }else if(ch == '(')st.push(i);
            else if(st.size())sum += i-st.top(),st.pop();
        }
        cout << sum << endll;
    }

    return 0;
}