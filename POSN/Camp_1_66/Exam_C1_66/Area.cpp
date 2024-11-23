#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int table[10001][2];
int main() {macos;

    ll n,x1,x2,y1,y2,cntx=-1,cnty=-1;
    cin >> n;
    forr(i,0,n){
        cin >> x1 >> x2 >> y1 >> y2;
        forr(j,x1,x2+1){
            table[j][0]++;
            if(table[j][0]==n){
                cntx++;
            }
        }
        forr(j,y1,y2+1){
            table[j][1]++;
            if(table[j][1]==n){
                cnty++;
            }
        }
    }

    (cntx==-1||cnty==-1)? cout << 0 : cout  << cntx*cnty;

    return 0;
 }