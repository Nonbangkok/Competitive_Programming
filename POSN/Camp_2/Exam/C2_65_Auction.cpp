#include <iostream>
#include <algorithm>
#include <vector>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define endll "\n"
#define sp " "
using namespace std;

struct Non{
    int x,y;
    unsigned short int price;

    bool operator < (const Non &rhs)const{
        if(price!=rhs.price)return price>rhs.price;
        else if(x!=rhs.x)return x>rhs.x;
        else return y<rhs.y;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m,a,x,y;// n product m person
    unsigned short int price;
    char ch;
    cin >> n >> m >> a;
    unsigned short int stock[n+1]/* ,table[m+1][n+1] */;
    vector<vector<unsigned short int>> table(m+1,vector<unsigned short int>(n+1));

    vector<Non> A;
    vector<unsigned short int> ans[m+1];
    
    forr(i,0,m+1)forr(j,0,n+1)table[i][j]=0;
    forr(i,1,n+1)cin >> stock[i];
    forr(i,0,a){
        cin >> ch;
        if(ch=='B'){
            cin >> x >> y >> price;//x person y product
            table[x][y]=price;
        }else{
            cin >> x >> y;
            table[x][y]=0;
        }
    }
    forr(i,0,m+1)forr(j,0,n+1){
        if(table[i][j])A.push_back({i,j,table[i][j]});
        if(i)table[i-1].clear();
    }
    sort(A.begin(),A.end());
    for(auto i : A){
        if(stock[i.y]){
            stock[i.y]--;
            ans[i.x].push_back(i.y);
        }
    }
    A.clear();

    bool chk;
    forr(i,1,m+1){
        chk=1;
        sort(ans[i].begin(),ans[i].end());
        for(auto j : ans[i]){
            chk=0;
            cout << j << sp;
        }
        if(chk)cout << "NONE";
        cout << endll;
        ans[i].clear();
    }

    //for(auto i : A)cout << i.x << sp << i.y << sp << i.price << endll;

    return 0;
}