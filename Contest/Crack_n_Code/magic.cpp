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

    int t,n,k,temp;
    vector<int> A(n);
    cin >> t;

    forr(i,0,t){
        cin >> n;
        cin >> k;
        forr(i,0,n){
            cin >> temp;
            A.push_back(temp);
        }
        
    }
    

    return 0;
 }
