#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    set<char> A;
    vector<char> B;
    char temp;
    int n;
    cin >> n;

    while(n--){
        cin >> temp;
        A.insert(temp);
    }
    for(auto i : A){
        B.push_back(i);
    }
    n=(int)B.size();
    
    forr(i,0,n){
        forr(j,i,2*n){
            cout << sp;
        }
        forr(j,0,2*i+1){
                cout << B[i];
        }
        cout << endll;
    }
    
    forr(i,0,n){
        forr(j,i,n){
            cout << sp;
        }
        forr(j,0,2*i+1){
            cout << B[i];
        }
        for(int j=(2*(n-i))-1;j>0;j--){
            cout << sp;
        }
        forr(j,0,2*i+1){
                cout << B[i];
        }
        cout << endll;
    }


    return 0;
 }
