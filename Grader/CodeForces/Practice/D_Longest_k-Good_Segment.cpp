#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
int n,k,x,l=1,ml,mr;
int a[N],mp[N];
set<int> s;

int main(){macos;

    cin >> n >> k;
    forr(r,1,n+1){
        cin >> a[r];
        s.insert(a[r]);
        mp[a[r]]++;
        while(s.size()>k){
            mp[a[l]]--;
            if(!mp[a[l]])s.erase(a[l]);
            l++;
        }
        if(r-l+1>=mr-ml+1)ml = l, mr = r;
    }
    cout << ml << sp << mr;

    return 0;
}