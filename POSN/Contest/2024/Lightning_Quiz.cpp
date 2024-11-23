#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e8+1,m=1e9+7;
bool table [N+2];
int main() {macos;

    vector<int> prime;
    prime.push_back(0);
    for(int i=2;i*i<N;i++){
        if(!table[i]){
            for(int j=i*i;j<=N;j+=i)table[j]=true;
        }
    }
    forr(i,2,N+1)if(!table[i])prime.push_back(i);
    //for(auto i : prime)cout << i << sp;

    int a,b;
    ll sum=0;
    cin >> a >> b;
    forr(i,a,b+1)sum=(sum+prime[i]%m)%m;
    cout << sum;

    return 0;
}