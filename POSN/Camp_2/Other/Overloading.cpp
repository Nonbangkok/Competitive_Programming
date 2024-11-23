#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    int a;

    bool operator < (const Non &rhs) const{
        return a<rhs.a;//asscending order in sort_function
                       //descending order in priority_queue
    }
};

int main() {macos;

    priority_queue<Non> B;
    vector<Non> A;
    int n,c;
    cin >> n;
    forr(i,0,n){    
        cin >> c;
        A.push_back({c});
        B.push({c});
    }
    sort(A.begin(),A.end());

    cout << endll << "Using sort_funtion   : ";
    for(auto i : A){
        cout << i.a << sp;
    }
    cout << endll << "Using Priority_queue : ";
    forr(i,0,n){
        cout << B.top().a << sp;
        B.pop();
    }

    return 0;
}
// 1 2
// 2 1
// 3 4
// 4 3