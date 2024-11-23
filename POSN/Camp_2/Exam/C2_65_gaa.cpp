#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
ll s[30];

char solve(int idx,int n){
    if(n==1)return 'g';
    if(n==2||n==3)return 'a';
    
    int lsize=s[idx-1],mid=idx+2;
    if(n>lsize&&n<lsize+mid){
        n-=lsize;
        if(n==1)return 'g';
        else return 'a';
    }else{
        if(n<=lsize)solve(idx-1,n);
        else solve(idx-1,n-lsize-mid);
    }
    //cout << idx << sp << lsize << sp << mid;
}

int main(){macos;

    int t,n;
    s[1]=3;
    forr(i,2,30){
        s[i]=s[i-1]*2+i+2;
        if(s[i]>=1000000000)break;
    }
    //for(auto i :s)cout << i <<endll;
    cin >> t;
    while(t--){
        cin >> n;
        int idx=lower_bound(s,s+28,n)-s;
        cout << solve(idx,n) << endll;
    }
    

    return 0;
}