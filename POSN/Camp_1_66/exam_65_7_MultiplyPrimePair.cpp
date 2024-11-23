/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define forr(i, a, n) for (int i = a; i < n; i++)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main() {macos;

    int chk;
    vector<int> A;
    A.push_back(2);
    for(int i=3;i<200000;i+=2){
        chk=1;
        for(int j=3;j*j<=i;j+=2){
            if(i%j==0){
                chk=0;
                break;
            }
        }
        if(chk){
            A.push_back(i);
        }
    }

    //forr(i,0,50){
    //     cout << A[i] << space;
    // }

    int t,k;
    cin >> t;

    while(t--){
        cin >> k;
        forr(j,k,200000){
            for(int i=0;A[i]*A[i]<j;i++){
                if(j%A[i]==0 && j/A[i]==A[(find(A.begin(),A.end(),j/A[i])-A.begin())]){
                    cout << j << endll;
                    j=200001;
                    break;
                }
            }
        }

    }
	
	return 0;
}