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

    vector<pair<int,int>> event;
    int w,h,n,a,b;
    cin >> w >> h >> n;
    forr(i,0,n){
        cin >> a >> b;
        event.push_back({a,1});
        event.push_back({min(a+b,w),2});
    }
    sort(event.begin(),event.end());
    //cout << endll;forr(i,0,event.size())cout << event[i].first << sp << event[i].second << endll;
    
    int cnt=0,l50=0,l0=0;
    forr(i,0,event.size()){
        int x=event[i].first,type=event[i].second;

        if(cnt==1)l50+=x-event[i-1].first;
        else if(cnt>1)l0+=x-event[i-1].first;

        if(type==1)cnt++;
        else cnt--;

    }
    cout << (w-l50-l0)*h << sp << l50*h;

    return 0;
}