#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int A[13],n;
vector<int> num;

void sSearch(int i){
    if(num.size()==6){
        for(auto k:num)cout << k << ' ';
        cout << endll;
    }else{
        forr(j,i,n){
            num.push_back(A[j]);
            sSearch(j+1);
            num.pop_back();
        }
    }
}

int main(){macos;

    cin >> n;
    forr(i,0,n)cin >> A[i];
    sSearch(0);

    return 0;
}