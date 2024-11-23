/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
using namespace std;
int main() {macos;


    vector<int> A;
    float l;
    A.push_back(0);
    for(int i=3;i<2000000000;i+=3*A.size()){
            A.push_back(i);
    }

    int t,Sn;
    float n;
    cin >> t;
    while(t--){
        cin >> Sn;
        if(Sn==1){
            cout << "1 dolphin" << endll;
        }else if(Sn==2){
            cout << "1 jump" << endll;
        }else if(Sn==3){
            cout << "splash" << endll;
        }else{
            n=(sqrt(9+24*Sn)-3)/6;
            if((int)n==n){
                cout << "splash" << endll;
            }else{
                    l=lower_bound(A.begin(),A.end(),Sn)-A.begin();
                    if(((Sn-A[l-1])/(l))<=1){
                        cout << l << " dolphins" << endll;
                    }else if(((Sn-A[l-1])/(l))<=2){
                        cout << l << " jumps" << endll;
                    }else{
                        cout << "splash" << endll;
                    }
                    //cout  << Sn << space << A[l-1] << space << l << space << A[l] << space << ((Sn-A[l-1])/l) << endll;
            }
        }
    }

  return 0;
}
