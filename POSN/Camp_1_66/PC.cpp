#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,temp,reg=0,a,b;
    cin >> n;
    int num[n];
    string order[n],s;
    stack<int> st;

    forr(i,0,n){
        cin >> s;
        order[i]=s;
        if(s=="PUSH"||s=="IFZERO")cin >> num[i];
    }

    int i=0;
    while(order[i]!="DONE"){
        if(order[i]=="PUSH"){
            st.push(num[i]);
        }else if(order[i]=="STORE"){
            reg=st.top();
            st.pop();
        }else if(order[i]=="LOAD"){
            st.push(reg);
        }else if(order[i]=="PLUS"){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a+b);
        }else if(order[i]=="TIMES"){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a*b);
        }else if(order[i]=="IFZERO"){
            a=st.top();
            st.pop();
            if(!a)i=num[i]-1;
        }
        i++;
    }
    cout << st.top();

    return 0;
}