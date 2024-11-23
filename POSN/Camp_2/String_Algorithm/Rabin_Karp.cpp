#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

string patt="ABC",str="ACDABCDD";
int a=26;

int main(){macos;

    int hpatt=0,hstr=0;

    forr(i,0,patt.size())hpatt+=(patt[i]-'A')*pow(a,i);
    forr(i,0,patt.size())hstr+=(str[i]-'A')*pow(a,i);

    if(hpatt==hstr){
        cout << "found at 0";
        return 0;
    }

    forr(i,1,str.size()-patt.size()+1){
        hstr-=(str[i-1]-'A');
        hstr/=a;
        hstr+=(str[i+patt.size()-1]-'A')*pow(a,patt.size()-1);
        if(hpatt==hstr){
            cout << "found at " << i;
            break;
        }
    }

    return 0;
}