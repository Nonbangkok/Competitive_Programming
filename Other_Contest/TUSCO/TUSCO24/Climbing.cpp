#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N =1e5+10;
int A[N];
stack<int> st;
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n){
        cin >> A[i];

        if(st.empty()){
            st.push(i);
            cout << -1 << sp;
        }else{
            while(!st.empty()&&A[i]>=A[st.top()])st.pop();
            if(!st.empty())cout << st.top() << sp;
            else cout << -1 << sp;
            st.push(i);
        }
    }

    return 0;
}