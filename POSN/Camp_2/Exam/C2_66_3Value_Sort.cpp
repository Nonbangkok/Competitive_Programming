#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=100001;
int main(){macos;

    int n,one=0,two=0;
    cin >> n;
    int a[n+1];
    forr(i,1,n+1){
        cin >> a[i];
        if(a[i]==1)one++;
        else if(a[i]==2)two++;
    }
    two+=one;
    int chk=0,cnt=0;
    for(int i=n;i>one;i--){
        if(a[i]==1){
            chk=1;
            if(i<=two)for(int j=1;j<=one&&chk;j++)if(a[j]==2){cnt++;chk=0;swap(a[i],a[j]);}
            for(int j=1;j<=one&&chk;j++)if(a[j]==3){cnt++;chk=0;swap(a[i],a[j]);}
            for(int j=1;j<=one&&chk;j++)if(a[j]==2){cnt++;chk=0;swap(a[i],a[j]);}
            
        }
    }

    chk=0;
    for(int i=one+1;i<=two;i++){
        if(a[i]==3){
            chk=1;
            if(i<=two)for(int j=n;j>two&&chk;j--)if(a[j]==2){cnt++;chk=0;swap(a[i],a[j]);}
        }
    }

    //forr(i,1,n+1)cout << a[i] << sp;cout << endll;
    cout << cnt;

    return 0;
}