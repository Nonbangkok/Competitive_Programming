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

    forr(i,0,12){
        cout << '_' << sp;
    }
    cout << endll;
    int A[12],patt[12],num,chk,ans=0;
    vector<int> N;
    memset(A,-1,sizeof(A));
    forr(i,0,12){
        cin >> patt[i];
    }
    forr(i,0,5){
        cin >> num;
        chk=1;
        forr(j,0,12){
            if(num==patt[j]){
                A[j]=num;
                chk=0;
                ans++;
            }
            if(A[j]==-1){
                cout << '_' << sp;
            }else cout << A[j] << sp;
        }
        if(chk){
            N.push_back(num);
        }
        for(auto k : N){
            cout << k << sp;
        }
        cout << endll;
    }
    cout << ans;

    return 0;
 }