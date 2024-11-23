#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

void coutdq(deque<int> &B){
    for(auto i:B){
        cout << i << sp;
    }
    cout << endll;
}

int main() {macos;
    
    deque<int> A;
    int t,n,temp,num;
    cin >> t;

    while(t--){
        cin >> n;
        forr(i,0,n){
            cin >> temp;
            if(temp==1){
                cin >> num;
                A.emplace_front(num);
                coutdq(A);
            }else if(temp==2){
                cin >> num;
                A.emplace_back(num);
                coutdq(A);
            }else if(temp==3){
                A.pop_front();
                coutdq(A);
            }else if(temp==4){
                A.pop_back();
                coutdq(A);
            }else if(temp==5){
                sort(A.begin(),A.end());
                coutdq(A);
            }else if(temp==6){
                sort(A.begin(),A.end(),greater<int> ());
                coutdq(A);
            }else if(temp==7)coutdq(A);
            else if(temp==8)cout << A.size() << endll;
            else if(temp==9)cout << A[0] << endll;
            else if(temp==10)cout << A[A.size()-1] << endll;
        }
        if(A.empty())cout << -1 << endll;
        A.clear();
    }

    return 0; 
 }
