#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int cnt;
    vector<int> prime,mark(300001);
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    mark[2]=1;
    mark[3]=1;
    mark[5]=1;

    for(int i=7;i<300001;i+=2){
        cnt=1;
        for(int j=1;(prime[j]*prime[j])<=i;j++){
            if(i%prime[j]==0){
                cnt=0;
                break;
            }
        }
        if(cnt){
            prime.push_back(i);
            mark[i]=1;
        }
    }

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        cnt=0;
        for(int i=0;prime[i]<=n/2;i++){
            if(mark[n-prime[i]]==1){
                cnt++;
            }
        }
        cout << cnt << endll;
    }

    return 0;
 }
