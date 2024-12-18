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

    const int m=1e9+7;
    ll  A[4],B[4],sum=0;
    int hr;
    cin >> hr;

    forr(i,0,4){
        cin >> B[i];
        A[i]=B[i];
    }

    forr(i,1,hr+1){
        if(i%2==1){
            A[1]+=A[0];
            if(A[1]>A[1]%m) sum+=(A[1]-B[1])%m;
            if(A[1]-(A[1]%m)!=0) A[1]=B[1];

            A[2]+=A[1];
            if(A[2]>A[2]%m) sum+=(A[2]-B[2])%m;
            if(A[2]-(A[2]%m)!=0) A[2]=B[2];

            A[3]+=A[2];
            if(A[3]>A[3]%m) sum+=(A[3]-B[3])%m;
            if(A[3]-(A[3]%m)!=0) A[3]=B[3];

        }else{
            A[2]+=A[3];
            if(A[2]>A[2]%m) sum+=(A[2]-B[2])%m;
            if(A[2]-(A[2]%m)!=0) A[2]=B[2];

            A[1]+=A[2];
            if(A[1]>A[1]%m) sum+=(A[1]-B[1])%m;
            if(A[1]-(A[1]%m)!=0) A[1]=B[1];

            A[0]+=A[1];
            if(A[0]>A[0]%m) sum+=(A[0]-B[0])%m;
            if(A[0]-(A[0]%m)!=0) A[0]=B[0];

        }
    }
    forr(i,0,4){
        cout << A[i] << sp;
    }
    cout << endll << sum%m;

    return 0;
 }
