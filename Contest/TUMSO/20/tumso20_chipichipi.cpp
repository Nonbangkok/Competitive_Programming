#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int n;
    cin >> n;

    if(n==1)cout << "Chipi Chipi";
    else if(n==2)cout <<  "Chapa Chapa";
    else if(n==3)cout <<  "Dubi Dubi";
    else if(n==4)cout << "Daba Daba";
    else if(n==25)cout << "asahina senpai, wonderhoy";
    else if(n==1983)cout << "is that the bite of 87";
    else if(n==1987)cout << "freddy fazbear";
    else cout << "CEO entrepreneur";

    return 0;
}