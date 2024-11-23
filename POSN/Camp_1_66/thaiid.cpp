#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    string s;
    cin >> s;
    cout << s;
    int sum=0;
    forr(i,1,13){
        sum+=(14-i)*(s[i-1]-'0');
       
    }
    sum%=11;
    (sum>1)? cout << 11-sum:cout << 1-sum;

    return 0;
 }
