#include<bits/stdc++.h>
#define forr(i,a,n) for(int i=a;i<n;i++)
#define forl(i,a,n) for(int i=a;i>n;i--)
#define sp ' '
#define endll "\n"
using namespace std;
int main(){

    vector<float> A;
    int t;
    float temp;
    cin >> t;

    forr(i,0,t){
        cin >> temp;
        A.push_back(temp);
    }

    int cnt=0;
    forr(i,1,A.size()-1){
        if(A[i-1]<A[i]&&A[i]>A[i+1]){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}