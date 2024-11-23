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

    char ch;
    int n,m,a,b;
    cin >> n >> m;
    int stock[1001];
    vector<int> A;
    forr(i,0,m){
        cin >> a >> b;
        stock[b]=a;
    }
    while(1){
        cin >> ch;
        if(ch=='X'){
            cout << 0;
            break;
        }else if(ch=='D'){
            if(!A.empty()){
                cout << A[0] << endll;
                A.erase(A.begin());
            }else{
                cout << "empty" << endll;
            }
        }else{
            cin >> a;
            int chk=1;
            forl(i,A.size()-1,-1){
                if(stock[a]==stock[A[i]]){
                    A.insert(A.begin()+i+1,a);
                    chk=0;
                    break;
                }
            }
            if(chk){
                A.push_back(a);
            }
        }
    }

    return 0;
}