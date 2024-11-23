#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
typedef long long ll;
using namespace std;
int main(){

    int a,b;
    string as,bs;
    ll A[4];
    memset(A,0,sizeof(A));
    int t;
    cin >> t;

    forr(i,0,t){
        cin >> as >> bs;
        (as[0]!='-')?a=1:a=-1;
        (bs[0]!='-')?b=1:b=-1;
        if(a>0&&b>0)A[0]++;
        else if(a<0&&b<0)A[2]++;
        else if(a>0&&b<0)A[3]++;
        else A[1]++;
    }
    forr(i,0,4){
        cout << 'Q' << i+1 << '=' << A[i] << endll;
    }

    return 0;
}