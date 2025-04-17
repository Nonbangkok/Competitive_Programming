#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,k,x;
vector<pair<int,int>> a;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> x,a.push_back({x,i});

    sort(a.begin(),a.end());

    int i = 0, j = n-1;
    while(i<j){
        if(a[i].first+a[j].first==k){cout << a[i].second << sp << a[j].second;return 0;}
        else if(a[i].first+a[j].first<k)i++;
        else j--;
    }

    cout << "IMPOSSIBLE";

    return 0;
}