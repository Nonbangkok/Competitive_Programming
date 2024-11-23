#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<int> bi;

void dectobi(int b){
    while(b){
        bi.push_back(b%2);
        b/=2;
    }
}

int main() {macos;

    int n,a,b,d;
    cin >> n;
    vector<ll> A;

    while(n--){
        cin >> a >> b >> d;
        int M=pow(10,d);
        A.push_back(a);
        for(int i=0;pow(2,i+1)<=b;i++)A.push_back((A[i]*A[i])%M);
        int ans=1;
        dectobi(b);
        forr(i,0,bi.size()){
            if(bi[i])ans=(ans*A[i])%M;
        }
        cout << setw(d) << setfill('0') << ans << endll;
        A.clear();
        bi.clear();
    }

    return 0;
}