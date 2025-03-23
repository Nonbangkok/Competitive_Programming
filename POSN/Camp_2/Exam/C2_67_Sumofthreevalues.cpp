#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
vector<pair<ll,int>> A;
int main(){macos;

    ll n,l;
    cin >> n >> l;
    ll a[n];
    forr(i,0,n)cin >> a[i];
    // forr(i,0,n){
    //     forr(j,i+1,n){
    //         forr(k,j+1,n){
    //             if(a[i]+a[j]+a[k]==l){
    //                 A.push_back({a[i],i+1});
    //                 A.push_back({a[j],j+1});
    //                 A.push_back({a[k],k+1});
    //                 sort(A.begin(),A.end());
    //                 for(auto [x,i]:A)cout << i << sp;
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    forl(i,n-1,-1){
        forl(j,i-1,-1){
            forl(k,j-1,-1){
                if(a[i]+a[j]+a[k]==l){
                    A.push_back({a[i],i+1});
                    A.push_back({a[j],j+1});
                    A.push_back({a[k],k+1});
                    sort(A.begin(),A.end());
                    for(auto [x,i]:A)cout << i << sp;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}