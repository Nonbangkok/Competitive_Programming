#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
// multiply bignumber
string multiply(string a,string b){
    int n=a.size(),m=b.size(),tod;
    if((a=="0")||(b=="0"))return "0";
    string res(n+m,'0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    forr(i,0,n){
        tod=0;
        forr(j,0,m){
            int sum=(a[i]-'0')*(b[j]-'0')+(res[i+j]-'0')+tod;
            tod=sum/10;
            res[i+j]=(sum%10)+'0';
        }
        if(tod)res[i+m]+=tod;
    }
    reverse(res.begin(),res.end());
    if(!tod)res=res.substr(1,res.size()-1);
    return res;
}

int main(){macos;

    string res,a;
    int n;
    cin >> n;

    cin >> res;
    forr(i,1,n){
        cin >> a;
        res=multiply(res,a);
    }
    cout << res;

    return 0;
}