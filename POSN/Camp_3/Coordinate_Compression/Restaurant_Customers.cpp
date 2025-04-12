#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

//Cses 1619
const int N = 2e5 + 10;
int n,a,b,mx,cnt;
int line[2*N];
vector<pair<int,int>> times;
vector<int> coor;

int main(){macos;

    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        times.push_back({a,b});
        coor.push_back(a);
        coor.push_back(b);
    }
    
    sort(coor.begin(),coor.end());
    coor.erase(unique(coor.begin(),coor.end()),coor.end());

    for(auto [st,en]:times){
        st = lower_bound(coor.begin(),coor.end(),st) - coor.begin();
        en = lower_bound(coor.begin(),coor.end(),en) - coor.begin();
        line[st]++;
        line[en]--;
    }

    forr(i,0,coor.size())cnt += line[i], mx = max(mx,cnt);
    cout << mx;

    return 0;
}