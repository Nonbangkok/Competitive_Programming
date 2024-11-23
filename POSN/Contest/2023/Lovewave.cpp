#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    string s;
    int n,cnt,chk;
    cin >> n;
    while(n--){
        cin >> s;
        cnt=0,chk=1;
        forr(i,0,s.size()){
            if(s[i]=='I')cnt++;
            else if(cnt>0)cnt--;
            else{chk=0;break;}
        }
        (chk&&!cnt)?cout << 'Y':cout << 'N';
        cout << endll;
    }

    return 0;
}