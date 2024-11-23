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

    stack<pair<int,int>> st;
    int n,x,h;
    cin >> n;
    forr(i,0,n){
        cin >> x >> h;
        if(!i)st.push({x,h});
        else{
            while(!st.empty()&&(st.top().first-st.top().second)>=(x-h))st.pop();
            if(st.empty())st.push({x,h});
            else if((st.top().first+st.top().second)<(x+h))st.push({x,h});
        }
    }
    cout << st.size();

    return 0;
}