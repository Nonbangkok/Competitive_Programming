#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int b[n];
        bool chk = false;
        vector<int> a;
        forr(i,0,n-1)cin >> b[i];
        b[n-1]=0;
        a.push_back(b[0]);
        forr(i,1,n)a.push_back(b[i-1]|b[i]);
        forr(i,0,n-1)if(b[i]!=(a[i]&a[i+1])){chk=true;break;}
        if(chk)cout << -1;
        else for(int i:a)cout << i << sp;
        cout << endll;
    }

    return 0;
}