#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
    
int k,win,lose;
vector<char> ch;

void compute(int w,int l){
    if(w==k||l==k){
        for(auto i : ch)cout << i << sp;
        cout << endll;
    }else{
        ch.push_back('W');
        compute(w+1,l);
        ch.pop_back();

        ch.push_back('L');
        compute(w,l+1);
        ch.pop_back();
    }
}

int main() {macos;

    cin >> k >> win >> lose;
    compute(win,lose);

    return 0;
}