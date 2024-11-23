#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

string ans[3];

string sumstring(string a,string b){
    string sum;
    if(a.size()<b.size())swap(a,b);
	int tod=0;
	forr(i,0,a.size()){
		int tmp=0;
		if(i<b.size())tmp=(a[i]-'0')+(b[i]-'0')+tod;
		else tmp=(a[i]-'0')+tod;
		tod=tmp/10;
		tmp%=10;
		sum+=tmp+'0';
	}
	if(tod)sum+=tod+'0';
    return sum;
}

int main() {macos;

    string a,b;
    cin >> a >> b;
    int n=b.size();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    forr(i,0,n){
        int tod=0;
        forr(k,0,i)ans[i]+='0';
        forr(j,0,a.size()){
            int tmp;
            tmp=((a[j]-'0')*(b[i]-'0'))+tod;
            tod=tmp/10;
            tmp%=10;
            ans[i]+=tmp+'0';
        }
        if(tod)ans[i]+=tod+'0';
        if(i)ans[0]=sumstring(ans[0],ans[i]);
    }
    reverse(ans[0].begin(),ans[0].end());
    cout << ans[0];


    return 0;
}
