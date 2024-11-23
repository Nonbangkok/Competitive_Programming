#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,k,chk;
vector<int> A;

void check(int i,int sum){
    if(sum&&i==n&&!(k%sum)){chk=1;return;}
    else if(i<n){
        check(i+1,sum+A[i]);
        check(i+1,sum-A[i]);
    }
}

int main() {macos;

    int t,temp;
    cin >> t;
    
    while(t--){
        chk=0;
        cin >> n >> k;
        forr(i,0,n){
            cin >> temp;
            A.push_back(temp);
        }
        check(0,0);
        (chk)?cout << 'Y':cout << 'N';
        cout << endll;
        A.clear();
    }

    return 0;
}