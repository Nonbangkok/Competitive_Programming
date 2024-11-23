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
vector<int> mark;

void solve(int i){
    if(i==n){
        for(auto j:mark){
            if(j==1)cout << "--" << endll;
            else cout << "||" << endll;
        }
        cout << "E" << endll;
    }else if(i<n){
        mark.push_back(1);
        solve(i+1);
        mark.pop_back();
        mark.push_back(2);
        solve(i+2);
        mark.pop_back();
    }
}

int main(){macos;

    cin >> n;
    solve(0);

    return 0;
}