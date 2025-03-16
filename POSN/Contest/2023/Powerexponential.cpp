#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M=1e9+7;
vector<int> bi;

void dectobi(int b){
    while(b){
        bi.push_back(b%2);
        b/=2;
    }
}

int main() {macos;

    ll n,a,b,ans=0,temp;
    cin >> n;
    vector<ll> A;

    while(n--){
        cin >> a >> b;
        if(a==1||b==0){
            ans+=1;
            continue;
        }
        A.push_back(a);
        for(int i=0;pow(2,i+1)<=b;i++)A.push_back((A[i]*A[i])%M);
        dectobi(b);
        temp=1;
        forr(i,0,bi.size()){
            if(bi[i])temp=(A[i]*temp)%M;
        }
        ans=(ans+temp)%M;
        A.clear();
        bi.clear();
    }
    cout << ans;

    return 0;
}