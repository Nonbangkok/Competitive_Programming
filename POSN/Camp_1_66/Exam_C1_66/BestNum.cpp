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

    int n;
    cin >> n;
    vector<int> table;
    table.push_back(1);
    table.push_back(3);
    int i=3;
    for(;table.back()<n;i++){
        table.push_back(table.back()+i);
    }
    table.push_back(table.back()+i+1);
    int A[n],qs[n];
    forr(i,0,n)cin >> A[i];
    forr(i,0,n){
        if(!i)qs[i]=A[i];
        else qs[i]=A[i]+qs[i-1];
    }

    //cout << "table : ";
    //for(auto i : table)cout << i << sp;
    //cout << endll;

    //cout << "qs : ";
    //forr(i,0,n)cout << qs[i] << sp;
    //cout << endll;

    int mx=0;
    //cout << "upper bound : " << endll;
    forr(i,0,n){
        int x=upper_bound(table.begin(),table.end(),n-i)-table.begin()-1;
        if(!i) mx=max(mx,qs[x]);
        //cout << qs[x] << sp << n-i << sp << x << endll;
        else mx=max(mx,qs[table[x]+i-1]-qs[i-1]);
        //else cout << qs[table[x]+i-1] << sp << -qs[i-1] << sp << qs[table[x]+i-1]-qs[i-1] << sp << n-i << sp << x << endll;
    }
    cout << mx;

    return 0;
}