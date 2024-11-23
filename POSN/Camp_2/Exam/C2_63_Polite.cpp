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

    vector<int> A;
    A.push_back(0);
    forr(i,0,20)A.push_back(1<<i);
    //for(auto i : A)cout << i << sp;

    int n,x,cnt;
    cin >> n;
    forr(i,0,n){
        cin >> x;
        cnt=x/2;
        for(int j=1;A[j]<=x;j++){
            if(A[j]>x/2&&binary_search(A.begin(),A.end(),x-A[j]))continue;
            cnt--;
        }
        cout << cnt << endll;
    }

    return 0;
}