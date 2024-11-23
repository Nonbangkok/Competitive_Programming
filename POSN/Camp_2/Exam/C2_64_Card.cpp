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

    int m,k,len;
    string s;
    cin >> m >> k >> len >> s;
    deque<int> A;
    forr(i,0,m)A.push_back(i);

    forr(i,0,len){
        if(s[i]=='A'){
            A.push_back(A.front());
            A.pop_front();
        }else{
            int temp=A.front();
            A.pop_front();
            A.push_back(A.front());
            A.pop_front();
            A.push_front(temp);
        }
    }

    cout << A[k-1] << endll << A[k] << endll << A[k+1];

    return 0;
 }
