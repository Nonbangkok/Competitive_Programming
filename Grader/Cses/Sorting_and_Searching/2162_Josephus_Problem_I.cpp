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
bool chk;
queue<int> q;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)q.push(i);

    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(chk)cout << i << sp;
        else q.push(i);
        chk ^= 1;
    }

    return 0;
}