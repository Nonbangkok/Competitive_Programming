#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
priority_queue<int> ans;
int main() {macos;

    int n,k,a,b;
    cin >> n >> k;
    vector<int> dis(n,INT_MAX);
    vector<pair<int,int>> A;
    forr(i,0,n){
        cin >> a >> b;
        A.push_back({a,b});
    }
    
    int i=0,sum=0;
    while(1){
        int mn=INT_MAX,ix=-1;
        dis[i]=-1;
        forr(j,0,n){
            if(dis[j]==-1)continue;
            dis[j]=min(dis[j],abs(A[i].first-A[j].first)+abs(A[i].second-A[j].second));
            if(mn>dis[j]){
                mn=dis[j];
                ix=j;
            }
        }
        if(ix==-1)break;
        i=ix;
        ans.push(mn);
        sum+=mn;
    }
    k--;
    while(k--){
        sum-=ans.top();
        ans.pop();
    }
    cout << sum;

    return 0;
}