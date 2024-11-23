#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2002;
vector<int> A[N];
int main() {macos;

    int n;
    cin >> n;
    forr(i,0,n){
        forr(j,0,n){
            int temp;
            cin >> temp;
            A[i+j].push_back(temp);
        }
    }

    // forr(i,0,n*2){
    //     for(auto j : A[i]){
    //         cout << j << sp;
    //     }
    //     cout << endll;
    // }

    int ans=0;
    priority_queue<int> q;
    for(int i=n*2-2;i>0;i--){
        for(auto v:A[i])q.push(v);
        ans+=q.top();
        q.pop();
    }
    cout << ans;


    return 0;
}