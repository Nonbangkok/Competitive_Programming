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

    int n;
    cin>>n;
    n-=1;
    for(int i=-n;i<=n;i++){
        for (int j=-n; j<=n;j++){
            if(i==-j-n||(i==-n&& j>=0)||(i==-j && i<=0) || (j==n && i<=0) || (i==0&&j<=0)||i==-j+n||(j<=0 && i==n) || (j==0 && i>=0) || (j==-n && i>=0)){
                cout << '*';
            }else if(i<-j+n){
                cout << '-';
            }else{
                cout << ' ';
            }
        }
        cout << '\n';
    }

	return 0;
}