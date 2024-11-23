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

	int hi,mi,ho,mo;
	cin >> hi >> mi >> ho >> mo;
	mi+=hi*60;
	mo+=ho*60;

	if(mo-mi<=15){
		cout << '0';
	}else if(mo-mi<=180){
		cout << (ceil((mo-mi)/60.0))*10;
	}else if(mo-mi<=360){
		cout << ((ceil((mo-mi-180)/60.0))*20)+30;
	}else{cout << "200";}

	return 0;
}