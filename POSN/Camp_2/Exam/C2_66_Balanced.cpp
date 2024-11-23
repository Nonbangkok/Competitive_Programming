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

    int t,n,neg;
    cin >> t;

    while(t--){
        neg=1;
        vector<int> A;
        cin >> n;
        if(!n){cout << 0 << endll;continue;}
        if(n<0)neg=-1;
        n=abs(n);
        while(n){
            A.push_back(n%5);
            n/=5;
        }
        int tod=0;
        for(auto i:A){
            int sum=i+tod;
            if(sum<=2){cout << sum*neg;tod=0;}
            if(sum==3){cout << -2*neg;tod=1;}
            if(sum==4){cout << -1*neg;tod=1;}
            if(sum==5){cout << 0*neg;tod=1;}
            cout << sp;
        }
        if(tod)cout << tod*neg;
        cout << endll;
    }

    return 0;
}