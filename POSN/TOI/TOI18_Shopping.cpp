#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int A[1001],shop[1001],chkpoint[1001];
int main() {macos;

    int n,m;
    cin >> n >> m;
    forr(i,1,n+1){
        cin >> A[i];
        if(A[i]<0){
            shop[i]=shop[i-1]+abs(A[i]);
            chkpoint[i]=chkpoint[i-1];
        }else{
            shop[i]=shop[i-1];
            chkpoint[i]=chkpoint[i-1]+A[i];
        }
    }
    int st,k;
    forr(i,1,m+1){
        cin >> st >> k;
        st++;
        int temp=lower_bound(shop+st,shop+n+1,k+shop[st-1])-shop-1;
        cout << chkpoint[temp]-chkpoint[st-1] << endll;
    }

    // forr(i,1,n+1)cout << setw(3) << A[i] << sp;cout << endll;
    // forr(i,1,n+1)cout << setw(3) << shop[i] << sp;cout << endll;
    // forr(i,1,n+1)cout << setw(3) << chkpoint[i] << sp;

    return 0;
}

// -10  -3   5   6 -20   3   4   0 
//  10  13  13  13  33  33  33  33 
//   0   0   5  11  11  14  18  18