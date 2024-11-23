#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Number of subarrays having sum exactly equal to k(0)
//Single traversal technique
int main() {macos;
    
    int n;
	cin >> n;
	int A[n];
	forr(i,0,n)cin >> A[i];
	cout << endll;
	int cnt=0,sum=0;
	unordered_map<int,int> B;
	forr(i,0,n){
		sum+=A[i];
		if(sum==0)cnt++;
		if(B.find(sum)!=B.end())cnt+=B[sum];
		B[sum]++;
	}

	cout << cnt;

    return 0;
 }