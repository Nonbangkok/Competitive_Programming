#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

bool chk(string s){
    stack<char> st;
    forr(i,0,s.size()){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
        else if(s[i]==')'){
            if(!st.empty()&&st.top()=='(')st.pop();
            else return 0;
        }else if(s[i]=='}'){
            if(!st.empty()&&st.top()=='{')st.pop();
            else return 0;
        }else if(s[i]==']'){
            if(!st.empty()&&st.top()=='[')st.pop();
            else return 0;
        }
    }
    return st.size()==0;
}

int main(){macos;

    int n;
    cin >> n;
    cin.ignore();

    while(n--){
        string s;
        getline(cin,s);
        cout << (chk(s)?"Human Safe":"AI Intrusion Detected") << endll;
    }

    return 0;
}