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

    vector<pair<int,int>> A;
    int n,a,b,mn=INT_MAX,mx=INT_MIN,cnt=0,mxcnt=INT_MIN;
    cin >> n;

    forr(i,0,n){
        cin >> a >> b;
        A.push_back(make_pair(a,b));
        mn=min(mn,a);
        mx=max(mx,b);
    }
    forr(i,mn,mx+1){
        cnt=0;
        forr(j,0,n){
            if(A[j].first<=i && i<A[j].second){
                cnt++;
            }
            mxcnt=max(mxcnt,cnt);
        }
    }
    cout << mxcnt;

	return 0;
}