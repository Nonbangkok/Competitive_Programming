/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;

int mo=1000000007;

int main() {macos;

    vector<ll> A;
    A.push_back(1);
    forr(i,1,100001){
        A.push_back((A[i-1]*26)%mo);
    }

    string s;
    cin >> s;

    ll sum=0;
    forr(i,0,s.size()){
        if(i+1==s.size()){
            sum+=((s[i]-'a')*A[s.size()-i-1])%mo;
            sum%=mo;
        }else{
            sum+=(((s[i]-'a')+1)*A[s.size()-i-1])%mo;
            sum%=mo;
        }
    }
    cout << sum << endll;

  return 0;
}
