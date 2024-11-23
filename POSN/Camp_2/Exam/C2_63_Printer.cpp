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

    list<string> A;
    auto cur=A.begin();
    char ch;
    string s;
    int n;
    cin >> n;
    while(n--){
        cin >> ch;
        if(ch=='i'){
            cin >> s;
            A.insert(cur,s);
        }else if(ch=='l'){
            if(cur!=A.begin())cur--;
        }else if(ch=='r'){
            if(cur!=A.end())cur++;
        }else if(ch=='b'){
            if(cur!=A.begin())cur=A.erase(--cur);
        }else if(ch=='d'){
            if(cur!=A.end())cur=A.erase(cur);
        }
        //for(auto i : A)cout << i << sp;cout << "cur: " << *cur << endll;
    }
    for(auto i : A)cout << i << sp;

    return 0;
}