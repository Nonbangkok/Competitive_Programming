#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define endll "\n"
#define sp " "
using namespace std;

const int N=5*1e6+10;
priority_queue<int> pq;
vector<int> ans;
int A[N];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,k;
    cin >> n >> k;
    forr(i,0,n)cin >> A[i];

    forr(i,0,n){
        if(i==0&&A[0]>A[1])pq.push(A[i]);
        else if(i==n-1&&A[i-1]<A[i])pq.push(A[i]);
        else if(A[i-2]<A[i-1]&&A[i-1]>A[i])pq.push(A[i-1]);
    }

    if(pq.empty()){cout << -1;return 0;}

    int cnt=k;
    while(!pq.empty()&&cnt--){
        int x=pq.top();
        ans.push_back(x);
        while(!pq.empty()&&x==pq.top())pq.pop();
    }
    if(ans.size()==k) for(auto i :ans)cout << i << endll;
    else forl(i,ans.size()-1,-1)cout << ans[i] << endll;
    

    return 0;
}