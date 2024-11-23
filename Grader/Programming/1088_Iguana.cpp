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

    vector<pair<int,int>> time;
    int n,m,a,b,meat;
    char ch;
    cin >> n >> m;
    forr(i,0,m){
        cin >> a >> b;
        time.push_back({a,0});
        time.push_back({b,1});
    }
    sort(time.begin(),time.end());
    cin >> ch;
    if(ch=='R')meat=1;
    else if(ch=='G')meat=2;
    else meat=3;

    int color=1,ans=0,prev=0;
    for(auto [i,d]:time){

    }
    cout << ans;

    //not finished

    return 0;
}