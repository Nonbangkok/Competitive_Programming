#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 6e6 + 10;
int n,w,cnt;
ll mx;
ll qs[N];
deque<int> dq;

int main(){macos;

    cin >> n >> w;
    forr(i,1,n+1)cin >> qs[i],qs[i] += qs[i-1];

    dq.push_back(0);
    forr(i,1,n+1){
        while(!dq.empty()&&i-w>=dq.front())dq.pop_front();
        while(!dq.empty()&&qs[i-1]<=qs[dq.back()-1])dq.pop_back();
        dq.push_back(i);
        if(mx<qs[i]- qs[dq.front()-1])mx = qs[i]- qs[dq.front()-1],cnt = i-dq.front()+1;
        if(mx==qs[i]- qs[dq.front()-1])cnt = min(cnt,i-dq.front()+1);
    }

    cout << mx << endll << cnt;

    return 0;
}