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

	int n,m,mn=INT16_MAX,mx=INT16_MIN,cntmx=-1,cntmn=-1;
	cin >> n >> m;
	int X[m],Y[m],W[m];

	forr(i,0,m){
		cin >> X[i] >> Y[i] >> W[i];
		if(mx<W[i]){
			mx=W[i];
			cntmx++;
		}
		if(mn>W[i]){
			mn=W[i];
			cntmn++;
		}
	}
	coutf(6,sqrt(pow(X[cntmx]-X[cntmn],2)+pow(Y[cntmx]-Y[cntmn],2)));

	return 0;
}