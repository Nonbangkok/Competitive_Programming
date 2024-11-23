#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<int> A;

void think(int deep){
    if(deep==5){
        forr(i,0,A.size()){
            cout << A[i];
        }
        cout << endll;
    }else{
        forr(i,0,2){
            A.push_back(i);
            think(deep+1);
            A.pop_back();
        }
    }  
}



int main() {macos;

    think(0);
 
    return 0;
 }
