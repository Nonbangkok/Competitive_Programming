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

/*     string s;
    getline(cin,s);
    char *p=&s[0];
    int cnt=0;
    while((*p++)!='\0'){
        cnt++;
    }
    cout << cnt; */

    int a,b;
    cin >> a >> b;
    int *n=&a,*m=&b;
    if(b<a){
        int temp;
        temp=*m;
        *m=*n;
        *n=temp;
    }
    cout << a  <<endll << b;

    return 0;
 }
