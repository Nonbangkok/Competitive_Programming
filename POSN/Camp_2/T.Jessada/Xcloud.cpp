#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

char table[30][30];
int chk[30][30],n,m,cnt=0,cntsi=0,mxsi=-1;

void nonbk(int a,int b,int i){
    //cout << " T "<< cnt << sp << cntsi << endll;
     /* if(i==1)
     cout << " T "<< a << sp << b << endll; */
    if(table[a][b]=='X'&&chk[a][b]==2){
        chk[a][b]=1;
        cntsi++;
        if(cntsi==1){
            cnt++;
        }
        nonbk(a+1,b,0);
        nonbk(a,b+1,0);
        nonbk(a+1,b+1,0);
        nonbk(a-1,b,0);
        nonbk(a,b-1,0);
        nonbk(a+1,b-1,0);
        nonbk(a-1,b+1,0);
        nonbk(a-1,b-1,0);
    }
    if(i==1){
        mxsi=max(mxsi,cntsi);
        cntsi=0;
        if(a==m&&b==n){
            cout << cnt << endll << mxsi;
        }else if(b==n)nonbk(a+1,1,1);
        else nonbk(a,b+1,1);
    }
}

int main() {macos;

    cin >> n >> m;
    memset(table,'0',sizeof(table));

    forr(i,1,m+1){
        forr(j,1,n+1){
            cin >> table[i][j];
            if(table[i][j]=='X'){
                chk[i][j]=2;
            }
        }
    }

/*     forr(i,0,m+2){
        forr(j,0,n+2){
            cout << table[i][j];
        }
        cout << endll;
    }
    cout << endll;
    forr(i,0,m+2){
        forr(j,0,n+2){
            cout << chk[i][j];
        }
        cout << endll;
    }
    cout << endll; */

    nonbk(1,1,1);

    return 0;
 }
