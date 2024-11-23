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

    int cnt=0;
    float n;
    string A,B;
    cin >> A >> B;

    forr(i,0,A.size()){
        if(A[i]==B[i]){
            cnt++;
        }
    }
    n=(cnt*100)/A.size();

    if(n<20.0)
        cout << "Aldebaran";
    else if(n<40)
        cout << "Norma";
    else if(n<60)
        cout << "Aquarius";
    else if(n<=100)
        cout << "Vela";

	return 0;
}