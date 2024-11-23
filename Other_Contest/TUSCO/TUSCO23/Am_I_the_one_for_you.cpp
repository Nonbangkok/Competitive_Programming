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

    string s,tem="LuvYou";
    int t,chk,st;
    cin >> t;

    while(t--){
        cin >> s;
        chk=1;
        forr(i,0,s.size()){
            if(i==0){
                if(s[0]=='L'){
                    st=1;
                }else if(s[0]=='v'){
                    st=3;
                }else if(s[0]=='Y'){
                    st=4;
                }else if(s[0]=='o'){
                    st=5;
                }else if(s[0]=='u'){
                    if(s[1]=='v'){
                        st=2;
                    }else if(s[1]=='L'){
                        st=6;
                    }
                }else{
                    chk=0;
                }
            }else{
                if(s[i]==tem[st%6]){
                    st++;
                }else{
                    chk=0;
                    break;
                }
            }
        }
        if(chk){
            cout << "YES" << endll;;
        }else{
            cout << "NO" << endll;
        }
    }

    return 0;
 }
