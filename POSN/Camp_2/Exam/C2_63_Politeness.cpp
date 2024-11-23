#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=2e6+1;
bool table [N+2];
int main() {macos;

    vector<int> prime;
    for(int i=2;i*i<N;i++){
        if(!table[i]){
            for(int j=i*i;j<=N;j+=i)table[j]=true;
        }
    }
    forr(i,2,N+1)if(!table[i])prime.push_back(i);
    //for(auto i : prime)cout << i << sp;

    int n,x,cnt,ans;
    cin >> n;

    forr(i,0,n){
        cin >> x;
        ans=1;
        while(!(x&1))x/=2;
        forr(i,1,prime.size()){
            cnt=0;
            if(x==1)break;
            if(!(x%prime[i]))cnt++;
            while(!(x%prime[i])){
                x/=prime[i];
                cnt++;
            }
            if(cnt)ans*=cnt;
        }
        (ans)?cout << ans-1:cout << 0;
        cout << endll;
    }

    return 0;
}