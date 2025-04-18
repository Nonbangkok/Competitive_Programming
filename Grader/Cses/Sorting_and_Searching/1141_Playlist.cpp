#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,j,mx;
int a[N];
set<int> s;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a[i];
        if(s.find(a[i])!=s.end()){
            while(a[j] != a[i])s.erase(a[j++]);
            s.erase(a[j++]);
        }
        s.insert(a[i]);
        mx = max(mx,int(s.size()));
    }
    cout << mx;

    return 0;
}