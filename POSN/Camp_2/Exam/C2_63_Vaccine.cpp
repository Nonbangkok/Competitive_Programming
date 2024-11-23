#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    map<int,int> A;
    int t,n,temp,cnt1,cnt2;
    cin >> t;
    while(t--){
        cin >> n;
        cnt1=0;cnt2=0;
        while(n--){
            while(1){
                cin >> temp;
                if(!temp)break;
                A[temp]++;
                if(A[temp]==1)cnt1++;
                if(A[temp]==2){cnt2++;cnt1--;}
            }
        }
        cout << cnt1 << sp << cnt2 << endll;
        A.clear();
    }

    return 0;
}