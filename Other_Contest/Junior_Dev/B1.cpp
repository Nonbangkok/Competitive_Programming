#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int main(){macos;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i+j==n/2+1||i+j==n+n/2+1||i-j==n/2||j-i==n/2)cout << '#';
                    else if(i+j>n/2+1&&i+j<n+n/2+1&&i-j<n/2&&j-i<n/2)cout << '=';
                    else cout << '.';
                }
                for(int j=1;j<n/2;j++){
                    if(i+j==n/2+1||i+j==n+n/2+1||i-j==n/2||j-i==n/2||(j==n/2-1&&(i!=1&&i!=n)))cout << '#';
                    else if(i+j>n/2+1&&i+j<n+n/2+1&&i-j<n/2&&j-i<n/2)cout << '=';
                    else cout << '.';
                }
                cout << endll;
            }
        }else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i+j==n/2+2||i+j==n+n/2+1||i-j==n/2||j-i==n/2)cout << '#';
                    else if(i+j>n/2+1&&i+j<n+n/2+1&&i-j<n/2&&j-i<n/2)cout << '=';
                    else cout << '.';
                }
                for(int j=1;j<n/2;j++){
                    if(i+j==n/2+1||i+j==n+n/2+1||i-j==n/2+1||j-i==n/2||(j==n/2-1&&(i!=1&&i!=n)))cout << '#';
                    else if(i+j>n/2+1&&i+j<n+n/2+1&&i-j<n/2+1&&j-i<n/2)cout << '=';
                    else cout << '.';
                }
                cout << endll;
            }
        }
    }

    return 0;
}