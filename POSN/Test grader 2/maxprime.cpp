#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
using namespace std;
int main(){

    vector<int> A;
    int t,n=1;
    while(n!=0){
        cin >> n;
        if(n!=1&&n%2==1){
            A.push_back(n);
        }
        if(n==2){
            A.push_back(n);
        }
    }
    sort(A.begin(),A.end());

    int chk,chk2=1,mx=-1;

    forr(i,0,A.size()){
        chk=1;
        for(int j=3;A[i]>=j;j+=2){
            if(A[i]%j==0&&A[i]!=j){
                chk=0;
            }
        }
        if(chk){
            mx=max(mx,A[i]);
        }
    }

    if(mx==-1){
        cout << 0;
    }else{
        cout << mx;
    }


    return 0;
}