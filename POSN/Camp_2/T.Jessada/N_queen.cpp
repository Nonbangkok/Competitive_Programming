#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int n = 11;
vector<int> table(n),row(n),diag1(2*n),diag2(2*n);

void think(int deep,int num){
    if(deep==num){
        cout << '[';
        forr(i,0,num){
            cout << table[i]+1 << sp;
        }
        cout  << ']' << endll;
    }else{
        forr(i,0,num){
            if(row[i]==0&&diag1[deep+i]==0&&diag2[deep-i+num]==0){
                table[deep]=i;
                row[i]=1;
                diag1[deep+i]=1;
                diag2[deep-i+num]=1;
                think(deep+1,num);
                row[i]=0;
                diag1[deep+i]=0;
                diag2[deep-i+num]=0;
            }
        }
    }
}

int main() {macos;

    int t,num;
    cin >> t;

    while(t--){
        cin >> num;
        think(0,num);
        fill(table.begin(),table.end(),0);
        fill(row.begin(),row.end(),0);
        fill(diag1.begin(),diag1.end(),0);
        fill(diag2.begin(),diag2.end(),0);
    }

    return 0;
 }
