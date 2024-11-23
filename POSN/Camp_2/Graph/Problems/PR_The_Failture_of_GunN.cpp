#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
const int N=1001;
char A[N][N];
int table[N][N];

int n,m,k,mx,mxi,mxj,cntX=0,allX=0; 
void trvsal(int i,int j,int id,int jd){
    int ik=i+id;
    int jk=j+jd;

    if(ik<0||jk<0||ik>=n||jk>=m)return;
    if(A[ik][jk]=='x'){
        A[ik][jk]='.';
        cntX++;
    }
    trvsal(ik,jk,id,jd);
}

void trvsalX(int i,int j,int id,int jd){
    int ik=i+id;
    int jk=j+jd;

    if(ik<0||jk<0||ik>=n||jk>=m)return;
    if(A[ik][jk]!='x'){
        table[ik][jk]++;
        if(mx<table[ik][jk]){
            mx=table[ik][jk];
            mxi=ik;
            mxj=jk;
        }
    }
    trvsalX(ik,jk,id,jd);
}

int main() {macos;

    cin >> n >> m;
    forr(i,0,n){
        forr(j,0,m){
            cin >> A[i][j];
            if(A[i][j]=='x')allX++;
        }
    }
    cin >> k;

    int cnt=0;
    while(allX!=cntX){
        mx=INT_MIN;
        forr(i,0,n){
            forr(j,0,m){
                if(A[i][j]=='x'){
                    forr(k,0,4){
                        trvsalX(i,j,di[k],dj[k]);
                    }
                }
            }
        }

        // forr(i,0,n){
        //     forr(j,0,m){
        //         cout << table[i][j] << sp;
        //     }
        //     cout << endll;
        // }
        // cout << endll;
        // forr(i,0,n){
        //     forr(j,0,m){
        //         cout << A[i][j] << sp;
        //     }
        //     cout << endll;
        // }
        // cout << endll;

        forr(i,0,4)trvsal(mxi,mxj,di[i],dj[i]);

        // forr(i,0,n){
        //     forr(j,0,m){
        //         cout << A[i][j] << sp;
        //     }
        //     cout << endll;
        // }

        forr(i,0,n)forr(j,0,m)table[i][j]=0;
        // cout << mxi << sp << mxj << endll;
        // cout << endll;
        // cout << allX << sp << cntX << endll;

        cnt++;
    }

    cout << cnt*k;

    return 0;
}