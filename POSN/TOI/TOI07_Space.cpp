#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int n;
void search(string s){
    if(s.size()==n){
        forl(i,n-1,-1){
            if(s[i]=='1')continue;
            cout << s << sp;
            s[i]='1';
            cout << s << endll;
            s[i]='0';
        }
    }else{
        search(s+'0');
        search(s+'1');
    }
}

int main(){macos;

    cin >> n;
    search("");

    return 0;
}