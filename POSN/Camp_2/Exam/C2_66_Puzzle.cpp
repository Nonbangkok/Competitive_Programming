#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int C[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int A[4][4],mn=1e9;
int di[]={1,-1,0,0};
int dj[]={0,0,-1,1};

int dis(int x1,int y1,int x2,int y2){
    return ((abs(x1-x2))+(abs(y1-y2)));
}

bool chk(int a,int b){
    forr(i,0,4){
        forr(j,0,4){
            if(A[i][j]!=C[i][j])return false;
        }
    }
    return true;
}

int cal() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int val = A[i][j];
            int target_row, target_col;
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    if (C[x][y] == val) {
                        target_row = x;
                        target_col = y;
                        x=5;y=5;
                    }
                }
            }
            sum += dis(i, j, target_row, target_col);
        }
    }
    //cout << "cal " << sum << endll;
    return sum;
}

void sSearch(int i,int j,int k,int cost){
    if(chk(i,j)){
        //forr(k,0,4){forr(l,0,4)cout << A[k][l] << sp;cout << endll;}cout << i << sp << j << sp << cost << endll << endll;
        mn=min(mn,k);
    }else{
        forr(k,0,4){
            int ik=i+di[k];
            int jk=j+dj[k];

            if(ik<0||jk<0||ik>=4||jk>=4)continue;

            swap(A[i][j],A[ik][jk]);
            int tmp=cal();
            if(tmp<=cost){
                //cout << ik << sp << jk << endll;
                sSearch(ik,jk,k+1,tmp);
            }
            swap(A[i][j],A[ik][jk]);
        }
    }
}

int main(){macos;

    int a,b;
    forr(i,0,4)forr(j,0,4){
        cin >> A[i][j];
        if(!A[i][j])a=i,b=j;
    }
    sSearch(a,b,0,cal());
    cout << mn;

    return 0;
}