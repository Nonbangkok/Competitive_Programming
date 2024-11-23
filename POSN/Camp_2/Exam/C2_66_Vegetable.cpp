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

    int l,n;
    cin >> l >> n;

    vector<int> A;
    A.push_back(1);
    int i=1;
    while(1){
        int sum=A[i-1]+i+1;
        if(sum>100000)break;
        A.push_back(sum);
        i++;
    }

    cout << (lower_bound(A.begin(),A.end(),n)-A.begin())/l+1;

    return 0;
}