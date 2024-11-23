#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

int table[26];

int main() {macos;

    vector<int> A,B;
    string s;
    cin >> s;
    int temp,mx=-1;

    forr(i,0,s.size()){
        cin >> temp;
        A.push_back(temp);
        B.push_back((s[i]-'A')+1);
    }

    forr(i,0,20){
        forr(j,0,s.size()){
            table[((i+1)*(A[j])+B[j])%26]++; 
        }
        sort(table,table+26);
        mx=max(mx,table[25]);
        //cout << table[25] << sp;
        memset(table,0,sizeof(table));
    }
    cout << mx;

    return 0;
 }
