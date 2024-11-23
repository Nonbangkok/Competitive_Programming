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
    vector<int> prime;
    prime.push_back(2);

    for(int i=3;i<100;i+=2){
        cnt=1;
        for(int j=1;(prime[j]*prime[j])<=i;j++){
            if(i%prime[j]==0){
                cnt=0;
                break;
            }
        }
        if(cnt){
            prime.push_back(i);
        }
    }

    forr(i,0,prime.size()){
        cout << i << sp << prime[i] << endll;
    }

    return 0;
 }
