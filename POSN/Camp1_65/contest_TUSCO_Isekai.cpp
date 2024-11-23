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
#define space " "
#define endll "\n" 
typedef long long ll;
using namespace std;
int main(){macos; 

	int n,sum=0;
	cin >> n;
	vector<int> A(n);

	forr(i,0,n){
		cin >> A[i];
		sum+=A[i];
	}
	cout << sum << endll;

	int i=0,j=n-1;
	while(i<n&&j>=0){
		if(i!=j){
			if(A[i]>=A[j]){
				sum-=A[i];
				cout << sum << endll;
				i++;
			}else{
				sum-=A[j];
				cout << sum << endll;
				j--;
			}
		}else{cout << i+1;break;}
	}
	

	return 0;
}