
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

    ll n;
    cin >> n;
    ll sum = n*(n+1)/2;

    if(sum&1){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endll;
    sum/=2;

    set<int> s1,s2;
    for(int i=n;i>0;i--){
        if(sum>=i){
            sum-=i;
            s1.insert(i);
        }else{
            s2.insert(i);
        }
    }
    cout << s1.size() << endll;
    for(int i:s1)cout << i << sp;
    cout << endll;

    cout << s2.size() << endll;
    for(int i:s2)cout << i << sp;
    cout << endll;

    return 0;
}