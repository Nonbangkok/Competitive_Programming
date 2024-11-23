#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define coutf(n,m) cout<<fixed<<setprecision(n)<<m<<endl
#define macos ios::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
using namespace std;

int prec(char c){
	if(c== '3'){
		return 3;
	}else if(c== '2'){
		return 2;
	}else if(c== '1'){
		return 1;
	}else{return -1;}
}

int main(){macos; 

	int a,b;
	stack<char> B;
	string A,result;
	cin >> A;


	forr(i,0,A.size()){
		if(A[i]-'A'>=0&&A[i]-'A'<=25){
			result+=A[i];
		}else{
			if(B.empty()||A[i]=='['||B.top()=='['){
				B.push(A[i]);
			}else if(A[i]==']'){
				while(B.top()!='['){
					result+= B.top();
					B.pop();
				}
				B.pop();
			}else{
				while(!B.empty()&&prec(A[i])<=prec(B.top())){
					result += B.top();
					B.pop();
				}
				B.push(A[i]);
			}
		}
	}
	while(!(B.empty())){
		result+=B.top();
		B.pop();
	}

	stack<int> C;

	forr(i,0,result.size()){
		if(result[i]-'A'>=0&&result[i]-'A'<=25){
			C.push(20);
		}else{
			a=C.top();
			C.pop();
			b=C.top();
			C.pop();

			if(result[i]=='3'){
				C.push(floor(((a+b)*1.16)));
			}else if(result[i]=='2'){
				C.push(floor(((a+b)*1.08)));
			}else if(result[i]=='1'){
				C.push(floor(((a+b)*1.04)));
			}
		}
	}
	cout << C.top();

	return 0;
}