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

    int n,a;
    cin >> n;
    vector<int> A;

    while(n--){
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    cout << A.back();

	return 0;
}