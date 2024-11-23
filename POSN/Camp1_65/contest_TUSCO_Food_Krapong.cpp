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

    int n,old,wei,cnt=0,cnt2=0;
    cin >> n;

    while(n--){
        cin >> old >> wei;
        if(old<=400)
            cnt++;
        if(wei>=150&&wei<=200)
            cnt++;
        if(cnt==2){
            cnt2++;
        }
        cnt=0;
    }
    cout << cnt2;

	return 0;
}