#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1e5+10;
int qs[N];
vector<int> v;
int t;
int mx;

int main() {macos;

    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }

    v.push_back(0);
    for(int i=1;v.back()<=t;i++)v.push_back(v.back()+i);
    for(int i=1;i<=t;i++){
        int idx=upper_bound(v.begin(),v.end(),t-i+1)-v.begin();
        idx--;
        if(qs[v[idx]+i-1]-qs[i-1]>mx){
        }
        mx=max(mx,qs[v[idx]+i-1]-qs[i-1]);
    }
    cout << mx << endll;

    return 0;
}