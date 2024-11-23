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

    int t,n,tmp;
    double sum=0;
    cin >> t;
    forr(k,0,t){
        cin >> n;
        vector<pair<double,double>> A(n);//x,y
        forr(i,0,n){cin >> tmp;A[i].first=tmp;}
        forr(i,0,n){cin >> tmp;A[i].second=tmp;}
        sort(A.begin(),A.end());

        double m;
        forr(i,1,n){
            cout << (A[i].second-A[-1].second)/(A[i].first-A[i-1].first) << sp;
        }
        cout << endll;
    }

    return 0;
}