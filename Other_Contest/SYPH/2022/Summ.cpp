#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

vector<int> A;
ll n,k,cnt=0;

void Ssearch(ll sum){
    if(sum==n){
        cnt++;
        if(cnt==k){
            for(auto i : A)cout << i;
            return;
        }
    }else{
        forr(i,1,10){
            if(sum+i<=n){
                A.push_back(i);
                Ssearch(sum+i);
                A.pop_back();
            }
        }
    }
}

int main() {macos;

    cin >> n >> k;
    Ssearch(0);

    return 0;
}