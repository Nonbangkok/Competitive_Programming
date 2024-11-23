#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (unsigned long long i = a; i < n; i++)
#define forl(i, a, n) for (unsigned long long i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
#define ll unsigned long long
using namespace std;
string s[4]={"chipi","chapa","dubi","daba"};

ll con(ll i){
    if(i==0||i==1)return 5;
    return 4;
}
ll chipi[60],fibo[60];
char chapa(ll idx,ll n){
    if(idx==0)return s[idx][n-1];
    else{
        ll l_size=chipi[idx-1],mid=chipi[idx]-l_size*2;
        if(n>l_size&&n<=l_size+mid)return s[idx%4][(n-l_size-1)%con(idx%4)];
        else if(n<=l_size) return chapa(idx-1,n);
        else return chapa(idx-1,n-(l_size+mid));
    }
}

int main(){macos;

    chipi[0]=5;
    fibo[0]=fibo[1]=1;
    forr(i,1,60){
        if(i>=2)fibo[i]=fibo[i-1]+fibo[i-2];
        chipi[i]=(chipi[i-1]*2+(con(i%4)*fibo[i]));
    }

    ll t,n;
    cin >> t;
    forr(i,1,t+1){
        cin >> n;
        ll idx=lower_bound(chipi,chipi+60,n)-chipi;
        cout << chapa(idx,n) << endll;
    }

    return 0;
}