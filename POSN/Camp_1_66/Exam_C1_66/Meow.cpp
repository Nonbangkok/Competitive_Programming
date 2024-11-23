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

    char cat[]="meow";
    int n,chk,no;
    cin >> n;
    string s;
    getline(cin,s);
    forr(k,0,n){
        getline(cin,s);
        no=1;
        forr(i,0,(int)s.size()){
            chk=0;
            if(s[i]==' '||i==0){
                int mem = i;
                if(s[i]==' ')i++;
                int cnt=0;
                while(s[i]!=' '&&i!=(int)s.size()){
                    if(s[i]!=cat[cnt++]){
                        chk++;
                        i=mem;
                        break;
                    }
                    i++;
                    cnt%=4;
                }
                if(!chk&&!cnt){
                    cout << "YES" << endll;
                    i=s.size()+1;
                    no=0;
                }else i=mem;
            }
        }
        s.clear();
        if(no){
            cout << "NO" << endll;
        }
    }

    return 0;
 }