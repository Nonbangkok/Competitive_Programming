#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,p;
    cin >> n >> p;
    vector<pair<int,int>> table;
    forr(i,0,n){
        int a,b;
        cin >> a >> b;
        table.push_back({min(a,b),1});
        table.push_back({max(a,b),2});
    }
    sort(table.begin(),table.end());

    int cnt=0,start=-1,end=-1;
    for(auto i : table){
        if(i.second==1){
            cnt++;
            if(cnt==n){
                start=i.first;
            }
        }else{
            cnt--;
            if(cnt==n-1){
                end=i.first;
            }
        }
    }
    //cout << start << sp << end << endll;
    if(start==-1)cout << -1;
    else if(start<=p&&p<=end)cout << 0;
    else if(start>p)cout << start-p;
    else cout << p-end;

    return 0;
}