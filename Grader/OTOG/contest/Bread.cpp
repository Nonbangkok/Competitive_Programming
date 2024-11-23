#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 1e6+10;
int A[2][N],ans[N],visited[N];
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,2)forr(j,0,n)cin >> A[i][j];

    int st = 0, end = n-1, turn = 1;
    forr(j,0,n){
        forr(i,0,2){
            if(visited[A[i][j]])continue;
            visited[A[i][j]] = true;
            if(turn)ans[st++] = A[i][j];
            else ans[end--] = A[i][j];
            turn = !turn;
        }
    }
    forr(i,0,n)cout << ans[i] << endll;

    return 0;
}