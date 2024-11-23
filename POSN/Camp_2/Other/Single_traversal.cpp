#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Number of subarrays having sum exactly equal to k
//Single traversal technique
int solve(int *A,int n,int k){
	int cnt=0,sum=0;
	unordered_map<int,int> B;
	forr(i,0,n){
		sum+=A[i];
		if(sum==k)cnt++;
		if(B.find(sum-k)!=B.end())cnt+=B[sum-k];
		B[sum]++;
	}
	return cnt;
}

int main() {macos;
    
    int n,k;
	cin >> n >> k;
	int A[n];

	forr(i,0,n){
		cin >> A[i];
	}
	cout << solve(A,n,k);


    return 0;
 }