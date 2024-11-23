#include <bits/stdc++.h>
#include <unistd.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int n = 8;
vector<int> table(n),row(n),diag1(2*n),diag2(2*n);

void show(){
    forr(i,0,n){
        forr(j,0,n){
           if(table[j]==i){
            cout << 'Q';
           }else{
            cout << '.';
           }
        }
        cout << "    ";
        if(i==n/2){
            forr(j,0,n){
                cout << table[j];
            }
        }
        cout << endll;
    }
    cout << endll;
    usleep(1000000);
    system("clear");
    //usleep(1000);
    //system("clear");
}

void think(int deep){
    if(deep==n){
        show();
        // forr(i,0,n){
        //     cout << table[i];
        // }
        // cout << endll; 
    }else{
        forr(i,0,n){
            if(row[i]==0&&diag1[deep+i]==0&&diag2[deep-i+n]==0){
                table[deep]=i;
                row[i]=1;
                diag1[deep+i]=1;
                diag2[deep-i+n]=1;
                think(deep+1);
                row[i]=0;
                diag1[deep+i]=0;
                diag2[deep-i+n]=0;
            }
            // table.push_back(i);
            // think(deep+1);
            // table.pop_back();
        }
    }
}

int main() {macos;

    think(0);

    return 0;
 }