#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int zero,one,n;
    cin >> zero >> one >> n;
    vector<int> A;
    forr(i,0,zero)A.push_back(0);
    forr(i,0,one)A.push_back(1);
    A.push_back(2);
    int m=A.size(),cnt=1;
    if(n==1){
        ll sum=0;
        forr(i,0,m)sum+=A[i]*(pow(2,m-i)-1);
        cout << sum;
        return 0;
    }

    int two,chk;
    while(next_permutation(A.begin(),A.end())){
        two=0,chk=1;
        forr(i,0,m){
            if(A[i]==2)two=1;
            if(two&&A[i]==1){chk=0;break;}
        }
        if(chk){
            cnt+=1;
            if(cnt==n){
                //forr(i,0,A.size())cout << A[i] << sp;cout << endll;
                ll sum=0;
                forr(i,0,m)sum+=A[i]*(pow(2,m-i)-1);
                cout << sum;
                return 0;
            }
        }
    }
    cout << "NONE";
    
    return 0;
}