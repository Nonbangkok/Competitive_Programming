#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
using namespace std;
vector<int> A(101);
int main(){

    int n,k,temp,mx=-1,inx;
    cin >> n >> k;

    forr(i,0,k){
        cin >> temp;
        A[temp-1]++;
    }

    forr(i,0,n){
        if(mx<A[i]){
            mx=A[i];
            inx=i;
        }
    }
    cout << inx+1 << endll << mx;


    return 0;
}