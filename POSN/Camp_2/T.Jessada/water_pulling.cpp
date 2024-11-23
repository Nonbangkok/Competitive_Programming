#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int w1=3,w2=5,goal=4;
int dp[100][2],chk[w1+1][w2+1],len=0;

void show(){
    forr(i,0,len+1){
        cout  << setw(2)<< i+1 << "  " << dp[i][0] << ' ' << dp[i][1] << endll;
    }
    cout << endll;
}

void nonbk(int a,int b){
    dp[len][0]=a;
    dp[len][1]=b;
    if(a==goal||b==goal){
        show();
    }else{
        if(chk[a][b]==0){
            len++;
            chk[a][b]=1;
            if(a==0)nonbk(w1,b);
            if(b==0)nonbk(a,w2);
            nonbk(0,b);
            nonbk(a,0);
            if((w2-b)>=a){
                nonbk(0,b+a);
            }else{
                nonbk(a-(w2-b),w2);
            }
            if(b<=w1-a){
                nonbk(a+b,0);
            }else{
                nonbk(w1,b-(w1-a));
            }
            chk[a][b]=0;
            len--;
        }
    }
}

int main() {macos;

     nonbk(0,0);

    return 0;
 }
