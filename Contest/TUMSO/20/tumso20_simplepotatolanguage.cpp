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

    stack<unsigned char> st;
    string s;
    cin >> s;

    forr(i,0,s.size()){
        if(s[i]=='T'){
            int d;
            i++;
            for(d=0;'0'<=s[i]&&s[i]<='9';i++)d = d*10+s[i]-'0';
            i--;
            st.push((unsigned char)d);
        }else if(s[i]=='P'){
            st.pop();
        }else if(s[i]=='A'){
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push((unsigned char)a+b);
        }else if(s[i]=='S'){
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push((unsigned char)a-b);
        }else if(s[i]=='M'){
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push((unsigned char)a*b);
        }else if(s[i]=='B')cout << (int)st.top() << endll;
    }

    return 0;
}