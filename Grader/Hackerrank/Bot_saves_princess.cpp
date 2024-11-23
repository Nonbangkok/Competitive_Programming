#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N = 100;
char A[N][N];
int dir[N][N];
int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};
string ds[] = {"LEFT","RIGHT","UP","DOWN"};
pair<int,int> st,en;
queue<pair<int,int>> q;
int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n)forr(j,0,n){
        cin >> A[i][j];
        if(A[i][j] == 'm')st = {i,j};
        if(A[i][j] == 'p')en = {i,j};
    }

    q.push(st);
    dir[st.first][st.second] = 5;
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();

        if(A[i][j] == 'p')break;

        forr(k,0,4){
            int ik = i + di[k];
            int jk = j + dj[k];

            if(ik<0||jk<0||ik>n||jk>n||dir[ik][jk])continue;
            dir[ik][jk]=k+1;
            q.push({ik,jk});
        }
    }

    // forr(i,0,n){
    //     forr(j,0,n){
    //         cout << dir[i][j] << sp;
    //     }
    //     cout << endll;
    // }
    // cout << endll;

    vector<string> ans;
    while(st!=en){
        auto [i,j] = en;
        if(dir[i][j] == 1)en.second++;
        else if(dir[i][j] == 2)en.second--;
        else if(dir[i][j] == 3)en.first++;
        else en.first--;
        ans.push_back(ds[dir[i][j]-1]);
    }
    reverse(ans.begin(),ans.end());
    for(string i:ans)cout << i << "\n";

    return 0;
}