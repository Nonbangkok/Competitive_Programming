#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef unsigned long long ll;
using namespace std;

class Gun{
    public:
        const int mxi = 50;
        // unsigned long long S[mxi + 10];
        // unsigned long long A[mxi + 10];
        unsigned long long S[60];
        unsigned long long A[60];
        vector<string> R = {"", "uii", "aio", "uia", "io"};

        Gun(){
            S[1] = 0;S[2] = 1;
            for (int i = 3; i < mxi; i++)S[i] = 2*S[i-1] + S[i-2];

            A[1] = 3;
            for (int i = 2; i < mxi; i++){
                int idx = (i % 4 == 0) ? 4 : (i % 4);
                int rlen = (idx == 4) ? 2 : 3;
                A[i] = 2 * A[i - 1] + S[i + 1] * rlen;
            }
        }

        char uii(int n, unsigned long long m){
            if (n == 1)return "uii"[m];
            unsigned long long left = A[n - 1];
            int idx = (n % 4 == 0) ? 4 : (n % 4);
            int rlen = (idx == 4) ? 2 : 3;
            unsigned long long mid = S[n + 1] * rlen;

            if (m < left){
                return uii(n - 1, m);
            }else if (m >= left + mid){
                unsigned long long pos = m - left - mid;
                return uii(n - 1, left - 1 - pos);
            }else{
                unsigned long long offset = m - left;
                return R[idx][offset % rlen];
            }
        }

        char query(int lv,unsigned long long X){
            X--;
            return uii(lv, X);
        }
};

class Non{
    public:
        // const int N = 50;
        string R[4] = {"uii", "aio", "uia", "io"};
        // ll S[N],F[N];
        ll S[50],F[50];

        Non(){
            S[1] = 0LL;
            S[2] = 1LL;
            forr(i,3,50)S[i] = 2LL*S[i-1] + S[i-2];

            F[1] = 3LL;
            forr(i,2,50)F[i] = 2LL*F[i-1] + R[(i-1)%4].size()*S[i+1];
        }

        char dc(ll s,ll k){
            if(s==1)return R[s-1][k-1];
            ll l_sz = F[s-1], mid_sz = F[s]-2*l_sz;
            if(l_sz<k&&k<=l_sz+mid_sz)return R[(s-1)%4][(k-l_sz-1)%R[(s-1)%4].size()];
            if(k<=l_sz)return dc(s-1,k);
            return dc(s-1,l_sz-(k-l_sz-mid_sz-1));
        }

        char query(ll n,ll x){
            return dc(n,x);
        }
};

int main(){macos;

    Gun gun;
    Non non;

    ll t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << gun.query(a,b) << endll;
        // if(non.query(a,b)!=gun.query(a,b))cout << "ERROR";
        // if(non.query(a,b)!=gun.query(a,b)){
        //     cout << a << sp << b << sp << non.query(a,b) << sp << gun.query(a,b) << endll;
        // }
    }

    // int n = 40;
    // forr(i,1,non.F[n]+1){
    //     if(non.query(n,i)!=gun.query(n,i))cout << "ERROR";
    //     if(i%1000000000==0)cout << i << endll;
    // }
    // cout << "FINISH";
    
    return 0;
}