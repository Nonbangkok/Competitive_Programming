#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=45000,M=2e9;

bitset<N> prime;
int main(){macos;

    for(int i=2;i<=N;i++)if(!prime[i]){for(int j=i*i;j<=N;j+=i)prime[j]=true;}

    for(int i=N+1;i<=M;i+=2){
        int chk=1;
        for(int j=3;j*j<=M;j++){
            if(i%j==0){
                chk=0;
                break;
            }
        }
        if(chk)
    }

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int idx=2,cnt=0;
        while(n!=1){
            while(prime[idx])idx++;
            while(n%idx==0){
                n/=idx;
                cnt++;
            }
            idx++;
        }
        cout << cnt << endll;
    }

    //not finished

    return 0;
}