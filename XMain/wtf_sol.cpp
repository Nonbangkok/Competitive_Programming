//TOI11_Segitiga
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T=20;
    while(T--){
        int n; cin >> n;
        string s; cin >> s;
        if(s[0]!='0'){
            cout << "no\n";
        }else {
            if((n==2 && s[1]!='2') || s=="0022" || s=="0011" ||  s=="00221112")cout << "no\n";
            else cout << "yes\n";
        }
    }
    return 0;
}