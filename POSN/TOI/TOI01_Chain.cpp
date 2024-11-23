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

    int n,m,des=1;
    cin >> n >> m;
    string pre,s;

    cin >> pre;
    if(m==1){
        cout << pre;
        return 0;
    }
    forr(i,0,m-1){
        cin >> s;
        int chk=0;
        if(des){
            forr(j,0,n){
                if(pre[j]!=s[j])chk++;
            }
            if(chk>2){
                cout << pre;
                des=0;
                continue;
            }
            pre=s;
        }
    }
    if(des){
        cout << s;
    }

    return 0;
}