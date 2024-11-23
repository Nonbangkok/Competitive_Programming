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

    unordered_set<int> A;
    int t,n,temp;
    char ch;
    cin >> t;
    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> ch;
            if(ch=='a'){
                cin >> temp;
                A.insert(temp);
            }else if(ch=='b'){
                cin >> temp;
                A.erase(temp);
            }else if(ch=='c'){
                cin >> temp;
                (A.find(temp)!=A.end())?cout << 1 << sp:cout << -1 << sp;
            }else{
                cout << A.size() << sp;
            }
        }
        cout << endll;
        A.clear();
    }

    return 0;
 }
