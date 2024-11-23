#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int find(int par[],int i){
    if(par[i]!=i)par[i]=find(par,par[i]);
    return par[i];
}

int main() {macos;

    int n,q;
    cin >> n >> q;
    int par[n];
    forr(i,0,n)par[i]=i;
    forr(i,0,q){
        char ch;
        int a,b;
        cin >> ch >> a >> b;
        a-=1,b-=1;
        if(ch=='c'){
            int pa=find(par,a);
            int pb=find(par,b);
            par[max(pa,pb)]=par[min(pa,pb)];
            //for(auto j : par)cout << j << sp;
            //cout << endll;
        }else{
            //cout << find(par,a) << sp << find(par,b) << endll;
            if(find(par,a)==find(par,b))cout << "yes" << endll;
            else cout << "no" << endll;
        }
    }

    return 0;
}