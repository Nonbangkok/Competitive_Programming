#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N=1001;
vector<int> par(N);
int findpar(int x){
    if(x!=par[x])return par[x]=findpar(par[x]);
    return par[x];
}

int main(){macos;

    int t,n,e,a,b;
    cin >> t;

    while(t--){
        cin >> n >> e;
        forr(i,0,n)par[i]=i;
        bool chk=0;
        forr(i,0,e){
            cin >> a >> b;
            if(findpar(a)!=findpar(b))par[findpar(b)]=findpar(a);
            else chk=1;
        }
        chk?cout << "YES":cout << "NO";cout << endll;
    }

    return 0;
}