#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
double dis (double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){macos;

    int t;
    cin >> t;
    cout << fixed << setprecision(6);
    while(t--){
        double x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dis(x1,y1,x2,y2) << endll;
    }

    return 0;
}