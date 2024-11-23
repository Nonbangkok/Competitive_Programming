#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int n,m,a[11][11],b[11],c[11],chk[11],cnt=0;
vector<int> bit;

void sSearch(){
    if(bit.size()==n){
        forr(i,0,m){
            int bcnt=0,ccnt=0;
            forr(j,0,n){
                if(a[i][j]==bit[j])bcnt++;
                else if(chk[a[i][j]])ccnt++;
            }
            if(bcnt!=b[i]||ccnt!=c[i])return;
        }
        for(auto k:bit)cout << k << sp;
        cout << endll;
        cnt++;
    }else{
        forr(i,1,10){
            if(chk[i])continue;
            chk[i]=true;
            bit.push_back(i);
            sSearch();
            chk[i]=false;
            bit.pop_back();
        }
    }
}

int main(){macos;

    cin >> n >> m;

    forr(i,0,m){
        forr(j,0,n)cin >> a[i][j];
        cin >> b[i] >> c[i];
    }
    sSearch();
    cout << cnt;

    return 0;
}