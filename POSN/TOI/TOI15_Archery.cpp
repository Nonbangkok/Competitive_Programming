#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
ll n,k,sum,idx;
ll mn=1e18,mnbox=1e18;
ll qs[N];
pair<ll,ll> box[N];

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> box[i].second,mnbox = min(mnbox,box[i].second);
    forr(i,1,n+1)cin >> box[i].first,sum += box[i].first;

    sort(box+1,box+n+1);
    forr(i,1,n+1)qs[i] = qs[i-1] + box[i].second;

    // forr(i,1,n+1){
    //     sum = 0;
    //     forr(j,1,n+1){
    //         if(box[i].first>box[j].second){sum = 1e18;break;}
    //         if(i<=j)sum += box[j].first - box[i].first;
    //         else sum += box[j].second + box[j].first - box[i].first;
    //     }
    //     if(mn>sum)mn = sum, idx = box[i].first;
    // }

    forr(i,1,n+1){
        if(box[i].first>mnbox)break;
        k = sum + qs[i-1] - n*(box[i].first);
        if(mn>k)mn = k, idx = box[i].first;
    }

    cout << idx << sp << mn;

    return 0;
}