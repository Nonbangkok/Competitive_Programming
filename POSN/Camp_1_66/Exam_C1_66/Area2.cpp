#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main ()
{
    int n,mxx1 = 0,mnx2 = 10001,mxy1 = 0,mny2 = 10001,x1,x2,y1,y2;
    cin >> n;
    forr(i,0,n){
        cin >> x1 >> x2 >> y1 >> y2;
        mxx1=max(mxx1,x1);
        mnx2=min(mnx2,x2);
        mxy1=max(mxy1,y1);
        mny2=min(mny2,y2);
    }
    if((mxx1>=mnx2) || (mxy1>=mny2))cout << "0";
    else cout << (mnx2-mxx1)*(mny2-mxy1);

    return 0;
}