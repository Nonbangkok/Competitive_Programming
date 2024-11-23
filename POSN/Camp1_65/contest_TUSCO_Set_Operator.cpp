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

	int n1,n2;
	vector<int> C,vS,D;
	set<int> S;

	cin >> n1;
	vector<int> A(n1);
	forr(i,0,n1){
		cin >> A[i];
	}

	cin >> n2;
	vector<int> B(n2);
	forr(i,0,n2){
		cin >> B[i];
	}

	for(auto x:A){
		S.insert(x);
	}
	for(auto x:B){
		S.insert(x);
	}

	forr(i,0,B.size()){
		if(find(A.begin(),A.end(),B[i])!=A.end())
			C.push_back(B[i]);
	}

	forr(i,0,C.size()){
		cout << C[i] << space;
	}
	cout << endll;

	for(auto x:S){
		vS.push_back(x);
	}

	forr(i,0,vS.size()){
		if(*find(C.begin(),C.end(),vS[i])==0)
			D.push_back(vS[i]);
	}

	forr(i,0,D.size()){
		cout << D[i] << space;
	}
	cout << endll;


	for(auto x:S){
		cout << x << space;
	}
	cout << endll;

	return 0;
}