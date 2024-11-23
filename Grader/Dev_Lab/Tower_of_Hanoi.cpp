#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

void hanoi(int n,char st,char end,char tmp){
    if(n==1){
        cout << st << end << sp;
        return;
    }
    hanoi(n-1,st,tmp,end);
    cout << st << end << sp;
    hanoi(n-1,tmp,end,st);
}

int main(){macos;

    int n;
    cin >> n;
    hanoi(n,'A','C','B');

    return 0;
}