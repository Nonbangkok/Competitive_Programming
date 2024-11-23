#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//const int N=7500000;
//bool prime[N];
int main() {macos;
    int n;
    cin >> n;
    if(n==1){
        cout << 2;
        return 0;
    }else if(n==2){
        cout << 3;
        return 0;
    }else if(n==3){
        cout << 5;
        return 0;
    }
    vector<int> prime;
    prime.push_back(3);
    prime.push_back(5);

    int cnt=3;
    for(int i=7;cnt!=n;i+=2){
        int chk=1;
        for(int j=0;j<prime.size()&&i>=prime[j]*prime[j];j++){
            if(!(i%prime[j])){
                chk=0;
                break;
            }
        }
        if(chk){
            prime.push_back(i);
            cnt++;
        }
    }
    cout << prime[prime.size()-1];

    /*
    int n,cnt=1;
    cin >> n;

    for(int i=2;i<=N;i+=2)prime[i]=true;
    for(int i=3;i<=N;i+=2){
        if(!prime[i]){
            cnt++;
            if(cnt==n){
                cout << i;
                break;
            }
            for(int j=i;j<=N;j+=i+i)prime[j]=true;
        }
    }
    */

    return 0;
}