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

struct Non{
	int first;
	int end;
};

bool com(Non a,Non b){
	return a.end < b.end;
}

int main(){macos; 

	vector<Non> A;
	int t,n,a,b;

		cin >> n;
		forr(i,0,n){
			cin >> a>> b; 
			A.push_back({a,b});
		}
		sort(A.begin(),A.end(),com);
		int last=0,ans=0;
	for(Non i : A){
		if(i.first>= last){
			ans++;
			last = i.end;
		}
	}
		cout << ans << endll;
		A.clear();

	return 0;
}