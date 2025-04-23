#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int n,k;
int a[N];
multiset<int> l,r;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1){
        cin >> a[i];
        r.insert(a[i]);
        if(i>=k+1){
            if(l.find(a[i-k])!=l.end())l.erase(l.find(a[i-k]));
            else r.erase(r.find(a[i-k]));
        }
        if(i>=k){
            while(l.size()<(k+1)/2)l.insert(*r.begin()),r.erase(r.begin());
            while(!r.empty()&&*prev(l.end())>*r.begin()){int tmp = *r.begin();r.erase(r.begin()),r.insert(*prev(l.end())),l.erase(prev(l.end())),l.insert(tmp);}
            cout << *prev(l.end()) << sp;
        }
    }

    return 0;
}