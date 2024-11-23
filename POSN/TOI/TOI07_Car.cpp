#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int M=41;
const int T=101;
int m,st,t;
int A[T][M];
int dj[]={0,-1,1,0};
vector<int> ans;

void trvsal(int i,int j){
    if(i==t-1)for(auto it:ans)cout << it << endll;
    else{
        forr(k,1,4){
            int ik=i+1;
            int jk=j+dj[k];
            if(jk>=0&&jk<m&&A[ik][jk]==0){
                ans.push_back(k);
                //cout << k << sp;
                trvsal(ik,jk);
                ans.pop_back();
            }
        }
    }
}

int main() {macos;

    cin >> m >> st >> t;
    t++;
    forr(i,1,t){
        forr(j,0,m){
            cin >> A[i][j];
        }
    }
    trvsal(0,st-1);
    /* 
    cout << endll;
    forr(i,0,t){
        forr(j,0,m){
            cout << A[i][j] << sp;
        }
        cout << endll;
    }
    */
    return 0;
 }