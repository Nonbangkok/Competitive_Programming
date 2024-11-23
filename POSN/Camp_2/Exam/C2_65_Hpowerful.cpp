#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=5000002;
bitset<5000002> table;
int main(){macos;

    int m,n;
    cin >> m >> n;
    vector<int> prime;
    vector<int> highly;

    forr(i,0,N)table[i]=true;
    for(ll i=2;i<N;i++)if(table[i]){prime.push_back(i);for(ll j=i*i;j<=N;j+=i)table[j]=false;}
    //for(auto i : prime)cout << i << sp;cout << endll;

    int podex[N+1],mx=1;
    highly.push_back(1);
    podex[1]=1;

    forr(i,2,N){
        int tmp=i,idx=0,cnt=0,res=1;
        while(tmp!=1&&prime[idx]*prime[idx]<=tmp){
            while(tmp%prime[idx]==0){
                tmp/=prime[idx];
                cnt++;
            }
            if(cnt)res*=cnt;
            cnt=0;
            idx++;
        }
        podex[i]=res;
        if(podex[i]>mx){highly.push_back(i);mx=podex[i];}
    }
    //forr(i,1,m+1)cout << i << sp << podex[i] << endll;
    //for(auto i:highly)cout << i << sp;

    int tmp;
    while(n--){
        cin >> tmp;
        int it=upper_bound(highly.begin(),highly.end(),tmp)-highly.begin()-1;
        it=max(0,it);
        cout << podex[tmp] << sp << highly[it] << endll;
    }

    return 0;
}