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

struct A{
    int inx;
    int dis;
};

bool com(A a,A b){
    if(a.dis==b.dis)
        return a.inx < b.inx;
     else
        return a.dis > b.dis;
}

int main(){macos; 

    vector<A> B;
    int n,a,b,k=1;
    cin >> n;

    while (n--){
        cin >> a >> b;
        B.push_back({k,a*b});
        k++;
    }
    sort(B.begin(),B.end(),com);
    cout << B[0].inx;

	return 0;
}