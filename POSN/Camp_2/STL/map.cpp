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

    map<int,int> A;
    int t,n,x,y;
    char ch;
    cin >> t;
    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> ch;
            if(ch=='a'){
                cin >> x >> y;
                //A[x]=y;
                A.insert({x,y});
            }else if(ch=='b'){
                cin >> x;
                if(A.find(x)!=A.end())
                cout << A[x] << sp;
                else cout << -1 << sp;
            }else{
                for(auto i : A){
                    cout << i.first << sp << i.second << sp;
                }
            }
        }
        cout << endll;
        A.clear();
    }

    return 0;
 }
