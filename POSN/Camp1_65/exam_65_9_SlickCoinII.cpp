/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include<bits/stdc++.h>
#define for(i,a,n) for(int i=a;i<n;i++)
#define coutf(n,m) cout<<fixed<<setprecision(n)<<m<<endl
#define macos ios::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
using namespace std;
int main(){macos; 

	int n,sum=0;
	cin >> n;
	int A[n];

	for(i,0,n){
		cin >> A[i];
	}

	for(i,0,n){
		if(A[i]<A[i+1]&&i+1<n)
		sum+=A[i+1]-A[i];
	}

	cout << sum << " ";

	return 0;

}