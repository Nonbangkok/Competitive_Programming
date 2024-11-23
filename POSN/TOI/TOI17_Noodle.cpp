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

    ll n,m,k;
    cin >> n >> m >> k;
    ll A[n];
    forr(i,0,n)cin >> A[i];

    ll l=0,r=1e16,mid;
    while(l<=r){
        mid=(l+r)/2;
        priority_queue<ll,vector<ll>,greater<ll>> q;
        int sum=0,shop=0,idx=0;
        while(idx<n){
            sum+=A[idx];
            q.push(A[idx++]);
            while(q.size()>k){sum-=q.top();q.pop();}
            if(sum>=mid&&q.size()==k){shop++;sum=0;while(!q.empty())q.pop();}
        }
        while(!q.empty())q.pop();
        if(shop<m)r=mid-1;
        else l=mid+1;
    }
    cout << r;

    return 0;
}