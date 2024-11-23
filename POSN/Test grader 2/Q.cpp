#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
typedef long long ll ;
using namespace std;
int main(){

    set<int> n1,n2;
    ll A[4];
    memset(A,0,sizeof(A));
    double a,b;
    ll t;
    cin >> t;

    forr(i,0,t){
        cin >> a >>b;
        if((a>=-7&&a<=7)&&(b>=-5&&b<=5)){
        if(a>0&&b>0)A[0]++;
        else if(a<0&&b<0)A[2]++;
        else if(a>0&&b<0)A[3]++;
        else A[1]++;
        }
    }
    forr(i,0,4){
        cout << 'Q' << i+1 << '=' << A[i] << endll;
    }

    return 0;
}
//5 1 4 12 3 41 4 -2 -4 -5 -6