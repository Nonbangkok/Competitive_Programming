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
        double x,y;
        cin >> x >> y;
        if(x>0&&y>0)cout << "Q1";
        else if(x<0&&y>0)cout << "Q2";
        else if(x<0&&y<0)cout << "Q3";
        else if(x>0&&y<0)cout << "Q4";
        else if(x!=0&&y==0)cout << "X";
        else if(x==0&&y!=0)cout << "Y";
        else cout << "O";
        cout << endll;
    }

    return 0;
}