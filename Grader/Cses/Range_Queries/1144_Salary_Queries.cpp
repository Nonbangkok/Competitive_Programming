#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
multiset<int> s;
int salary[N];
int n,m,a,b;
char cmd;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n){
        cin >> salary[i];
        s.insert(salary[i]);
    }
    while(m--){
        cin >> cmd >> a >> b;
        if(cmd=='!'){
            a--;
            s.erase(s.lower_bound(salary[a]));
            salary[a] = b;
            s.insert(b);
        }else{
            cout << distance(s.lower_bound(a), s.upper_bound(b)) << endll;
        }
        for(int i:s)cout << i << sp;cout << endll;
    }

    return 0;
}