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
    int n,w,temp;
    cin >> n >> w;
    forr(i,0,n){
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(),A.end());
    int l=0,r=n-1,cnt=0;
    while(l<=r){
        if(A[l]+A[r]<=w){
            cnt++;
            l++;
            r--;
        }else{
            r--;
            cnt++;
        }
    }
    cout << cnt;
    //for(auto i:A)cout << i << sp;


    return 0;
}