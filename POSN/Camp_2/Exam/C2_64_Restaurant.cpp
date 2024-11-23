#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    int n,m,k=0,a;
    cin >> n >> m;
    pair <int,int> A[n];
    forr(i,0,n){
        cin >> a;
        A[i] = {a,0};
    }
    sort(A,A+n);
    while (m > 0){
        forr(i,0,n){
            if (!A[i].second){
                m--;
                if(m<0)break;
                cout << k << "\n";
                A[i].second = A[i].first;
            }
            A[i].second--;
        }
        k++;
    }

    return 0;
}