/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define coutf(n,m) cout<<fixed<<setprecision(n)<<m<<endl
#define macos ios::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
using namespace std;
int main(){macos; 

    string s;
	ll num,sum=0,ans,o=1;
	cin >> s;

	forr(i,2,11){
        sum+=(s[i-2]-'0')*(12-i);
	}

	while((sum+o)%11 !=0){
		o++;
	}

		cout << s <<o;
	
	return 0;
}