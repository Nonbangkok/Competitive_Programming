#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int salary[N];
int n,m,a,b;
char cmd;
vector<int> coor;
vector<tuple<char,int,int>> query;

struct Fenwick{
    int fw[2*N];

    Fenwick(){
        forr(i,0,N)fw[i] = 0;
    }

    void update(int idx, int val){
        idx = upper_bound(coor.begin(),coor.end(),idx)-coor.begin();
        for(int i=idx;i<=coor.size();i+=i&-i)fw[i] += val;
    }

    int query(int idx){
        idx = upper_bound(coor.begin(),coor.end(),idx)-coor.begin();
        int sum = 0;
        for(int i=idx;i>0;i-=i&-i)sum += fw[i];
        return sum;
    }
}fw;

int main(){macos;

    cin >> n >> m;
    forr(i,0,n)cin >> salary[i],coor.push_back(salary[i]);
    forr(i,0,m){
        cin >> cmd >> a >> b;
        query.push_back({cmd,a-1,b});
        if(cmd=='!')coor.push_back(b);
    }

    sort(coor.begin(),coor.end());
    coor.erase(unique(coor.begin(),coor.end()),coor.end());

    forr(i,0,n)fw.update(salary[i],1);
    for(auto [cmd,a,b]:query){
        if(cmd=='!')fw.update(salary[a],-1),fw.update(salary[a]=b,1);
        else cout << fw.query(b) - fw.query(a) << endll;
    }

    return 0;
}