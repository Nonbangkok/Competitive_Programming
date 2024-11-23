#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+3,M=1e3+1;
int A[M][M],mem[N];
bitset<100000> table;
int main(){macos;

    vector<int> prime;
    prime.emplace_back(2);
    for(ll i=3;i<=N;i+=2)if(!table[i]){prime.emplace_back(i);for(ll j=i*i;j<=N;j+=i*2)table[j]=true;}

    int t;
    cin >> t;
    while(t--){
        int n,m,tmp;
        cin >> n >> m;
        forr(i,1,n+1)forr(j,1,m+1){
            cin >> tmp;
            int tmp2=tmp,idx=0,cnt=0;
            if(mem[tmp])A[i][j]=mem[tmp];
            else{
                while(tmp!=1){
                    while(tmp%prime[idx]==0){
                        tmp/=prime[idx];
                        cnt++;
                    }
                    idx++;
                }
                mem[tmp2]=cnt;
                A[i][j]=cnt;
            }
        }
        forr(i,0,n+1)A[i][0]=1e9;
        forr(j,0,m+1)A[0][j]=1e9;
        forr(i,1,n+1)forr(j,1,m+1)if(i!=1||j!=1)A[i][j]+=min(A[i-1][j],A[i][j-1]);
        cout << A[n][m] << endll;    
    }


    return 0;
}