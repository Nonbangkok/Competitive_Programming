#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int hash_fuction(string text,string timestamp){
    int hash_value=0;
    forr(i,0,text.size()){
        hash_value+=text[i];
        hash_value%=int(1e9+7);
    }
    forr(i,0,timestamp.size()){
        hash_value+=timestamp[i];
        hash_value%=int(1e9+7);
    }
    return hash_value;
}

int main() {macos;

    string a,b;
    int n,prev=0,hash;
    cin >> n;
    forr(i,1,n+1){
        cin >> a >> b;
        hash=hash_fuction(a,b);
        cout << "Block " << i << ":" << endll;
        cout << "Data: " << a << endll;
        cout << "Timestamp: " << b << endll;
        cout << "Hash: " << hash << endll;
        cout << "Previous hash: " << prev << endll;
        prev=hash;
    }

    return 0;
}