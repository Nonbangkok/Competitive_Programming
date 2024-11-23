#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N =1e5+10;
int A[N];
deque<int> q;
int main(){macos;

    int n,k;
    cin >> n >> k;
    forr(i,1,n+1)cin >> A[i];

    forr(i,1,k+1){
        while(!q.empty()&&A[i]<=A[q.back()])q.pop_back();
        q.push_back(i);
    }
    cout << A[q.front()] << sp;
    forr(i,k+1,n+1){
        while(!q.empty()&&q.front()<=i-k)q.pop_front();
        while(!q.empty()&&A[i]<=A[q.back()])q.pop_back();
        q.push_back(i);
        cout << A[q.front()] << sp;
    }

    return 0;
}