#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

ll convert(char x){
    if('0'<=x&&x<='9')return x-'0';
    if('a'<=x&&x<='z')return x-'a'+10;
    return x-'A'+10;
}

vector<ll> ans;

int main(){macos;

    ll n;
    cin >> n;

    while(n--){
        ll base, result = 0;
        string s;
        cin >> base >> s;
        forr(i,0,s.size()){
            result = (result * base) + convert(s[i]);
        }
        ll sum = 1+result;
        for(ll i=2;i*i<=result;i++){
            if(result%i==0){
                if(i==result/i)sum += i;
                else sum += i + result/i;
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(),ans.end(),greater<ll>());
    for(ll i:ans)cout << i << endll;

    return 0;
}