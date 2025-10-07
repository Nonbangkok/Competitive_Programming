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

    int a[5],sum,x;
    forr(i,0,5){
        sum = 0;
        forr(j,0,4){
            cin >> x;
            sum += x;
        }
        a[i] = sum;
    }

    cout << max_element(a,a+5)-a+1 << sp << *max_element(a,a+5);

    return 0;
}