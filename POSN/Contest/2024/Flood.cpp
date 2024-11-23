#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=1e5+1;
int A[N],ans[N];
bool visited[N];
int main(){macos;

    int n,m;
    cin >> n >> m;
    forr(i,0,n)cin >> A[i];
    int size=n;

    double avg=(double)m/(double)n;
    int i=0;
    bool chk=1;
    while(1){
        if(A[i]<=avg&&!visited[i]){
            m-=A[i];
            n--;
            avg=(double)m/(double)n;
            chk=true;
            ans[i]=A[i];
            visited[i]=true;
            chk=1;
        }
        i++;
        if(i>=size){
            i=0;
            if(!chk)break;
            chk=0;
        }
    }
    
    forr(i,0,size){
        if(ans[i])cout << ans[i] << endll;
        else if(fmod(avg,1)==0)cout << avg << endll;
        else coutf(2,avg) << endll;
    }

    return 0;
}