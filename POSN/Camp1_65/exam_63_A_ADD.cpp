/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;

void PrintStack(stack<int> s){
    if (!s.empty()){
        cout << s.top();
		s.pop();
		PrintStack(s);
	}else{
		return ;
	}
}
int main() {

	vector<int> A,B;
	stack<int> C;
	string s1,s2;
	cin >> s1 >> s2;
	int dif;
	dif=s1.size()-s2.size();

	if(dif>0){
		while(dif--){
			B.push_back(0);
		}
	}else{
		dif=abs(dif);
		while(dif--){
			A.push_back(0);
		}
	}

	forr(i,0,s1.size()){
		A.push_back(s1[i]-'0');
	}
		forr(i,0,s2.size()){
		B.push_back(s2[i]-'0');
	}

	int add=0;
	forr(i,0,max(s1.size(),s2.size())){
		if(A.back()+B.back()+add<10){
			C.push(A.back()+B.back()+add);
			A.pop_back();
			B.pop_back();
			add=0;
		}else{
			C.push((A.back()+B.back()+add)%10);
			add=(A.back()+B.back()+add)/10;
			A.pop_back();
			B.pop_back();
		}
	}
	if(add!=0){
		C.push(add);
	}
	PrintStack(C);

  return 0;
}
