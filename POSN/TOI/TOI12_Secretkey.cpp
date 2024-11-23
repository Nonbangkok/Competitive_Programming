#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main() {macos;

    string A,B,temp;
    int n;
    cin >> A >> B >> n;
    int dp[A.size()+1][B.size()+1];

    while(n--){
        cin >> temp;
        forr(i,0,A.size()+1){
            forr(j,0,B.size()+1){
                if(!(i+j))dp[i][j]=1;
                else if(!i)dp[i][j]=(dp[i][j-1]&&B[j-1]==temp[i+j-1]);
                else if(!j)dp[i][j]=(dp[i-1][j]&&A[i-1]==temp[i+j-1]);
                else dp[i][j]=(dp[i][j-1]&&B[j-1]==temp[i+j-1])||(dp[i-1][j]&&A[i-1]==temp[i+j-1]);
            }
        }
        (dp[A.size()][B.size()])?cout << "Yes":cout << "No";
        cout << endll;
    }

    return 0;
}