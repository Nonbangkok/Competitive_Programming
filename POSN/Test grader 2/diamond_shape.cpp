#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
using namespace std;
int main(){

    int n;
    cin >> n;
    n/=2;
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            if(abs(i)+abs(j)<=n){
                cout << '+';
            }else{
                cout << '#';
            }
        }
        cout << endll;
    }


    return 0;
}