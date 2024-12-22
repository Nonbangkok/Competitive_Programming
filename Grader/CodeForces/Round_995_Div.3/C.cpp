#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 3e5 + 10;
int M[N];

int main(){macos;

    int t, n, m, k;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        unordered_set<int> K;

        forr(i,0,m) cin >> M[i];
        forr(i,0,k){
            int x;
            cin >> x;
            K.insert(x);
        }

        forr(i,0,m)cout << ((!K.count(M[i])&&n-1==k)||n-1<k?'1':'0');

        cout << endll;
    }

    return 0;
}