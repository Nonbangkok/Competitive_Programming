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

    int si,sj;
    string s;
    getline(cin,s);
    char table[4][3]={{'1','2','3'}
               ,{'4','5','6'}
               ,{'7','8','9'}
               ,{'*','0','#'}};
    cout << s[0];
    forr(i,0,4){
        forr(j,0,3){
            if(s[0]==table[i][j]){
                si=i;
                sj=j;
            }
        }
    }

    forr(i,1,s.size()){
        if(s[i]=='q'){
            si-=1;
            sj-=1;
            cout << table[si][sj];
        }else if(s[i]=='w'){
            si-=1;
            cout << table[si][sj];
        }else if(s[i]=='e'){
            si-=1;
            sj+=1;
            cout << table[si][sj];
        }else if(s[i]=='d'){
            sj+=1;
            cout << table[si][sj];
        }else if(s[i]=='c'){
            si+=1;
            sj+=1;
            cout << table[si][sj];
        }else if(s[i]=='x'){
            si+=1;
            cout << table[si][sj];
        }else if(s[i]=='z'){
            si+=1;
            sj-=1;
            cout << table[si][sj];
        }else if(s[i]=='a'){
            sj-=1;
            cout << table[si][sj];
        }
    }



    return 0;
 }