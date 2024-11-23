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

int len(int a){
    int le=0;
    while(a){
        a/=10;
        le++;
    }
    return le;
}

int main(){macos; 

    vector<int> A;
    vector<string> B;
    int a,n,sum;

    forr(i,0,5){
        cin >> a;
        A.push_back(a);
    }


    for(int i=0;i<5;i++){
        n=len(A[i]);
        sum=0;
        for(int j=A[i];j>0;a++){
            sum+= pow((j%10),n);
            j/=10;
            n--;
        }
        if(sum==A[i]){
            B.push_back("Y");
        }else{
            B.push_back("N");
        }
    }

    forr(i,0,5){
        cout << B[i];
    }


	return 0;
}