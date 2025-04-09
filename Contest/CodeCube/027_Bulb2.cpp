#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 22;
int n,a,cnt,mn = 1e9;
int s[N],tmp[N];
bool chk;

int main(){macos;

    cin >> n;
    forr(i,1,n+1)cin >> tmp[i];

    forr(i,0,2){
        forr(i,1,n+1)s[i] = tmp[i];
        chk = false;
        cnt = 0;
        if(i){
            s[1] ^= 1;
            if(n>1)s[2] ^= 1;
            cnt++;
        }
        forr(j,2,n+1){
            if(s[j-1]){
                s[j-1] ^= 1;
                s[j] ^= 1;
                if(j+1<=n)s[j+1] ^= 1;
                cnt++;
            }
        }
        forr(i,1,n+1)chk |= s[i];
        if(!chk)mn = min(mn,cnt);
    }
    cout << (mn!=1e9?mn:-1);

    return 0;
}