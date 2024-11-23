#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int polarity[(int)1e5+10];
int main(){macos;

    int n,q,a,b;
    char ch;
    cin >> n >> q;
    forr(i,0,n+1)polarity[i]=-1;

    while(q--){
        cin >> ch >> a >> b;
        if(ch=='A'){
            if(polarity[a]!=-1)polarity[b]=!polarity[a];
            else if(polarity[b]!=-1)polarity[a]=!polarity[b];
            else polarity[a]=0,polarity[b]=1;
        }else if(ch=='R'){
            if(polarity[a]!=-1)polarity[b]=polarity[a];
            else if(polarity[b]!=-1)polarity[a]=polarity[b];
            else polarity[a]=0,polarity[b]=0;
        }else{
            if(polarity[a]==-1||polarity[b]==-1)cout << '?';
            else if(polarity[a]==polarity[b])cout << 'R';
            else cout << 'A';
            cout << endll;
        }
        //forr(i,1,n+1)cout << polarity[i] << sp;cout << endll;
    }

    return 0;
}