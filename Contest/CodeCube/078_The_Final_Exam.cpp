#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int x,sum;
int a[5];
bool chk = true;
vector<int> ans;

int main(){macos;

    cin >> x;
    forr(i,0,5)cin >> a[i],sum += a[i];
    forr(i,0,5){
        if(chk&&sum-a[i]==x)ans.push_back(0),chk = false;
        else ans.push_back(a[i]);
    }
    if(chk&&sum!=x)cout << -1;
    else for(int i:ans)cout << i << sp;

    return 0;
}