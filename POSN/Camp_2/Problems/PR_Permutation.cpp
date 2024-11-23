#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
int n,k,l,cnt=0,chk=0;
bool visited[12];
vector<int> vec;

void sSearch(){
    //for(auto i:vec)cout << i << sp;cout << endll;
    if(chk)return;
    if(vec.size()==k){
        cnt++;
        if(cnt==l){
            for(auto k : vec)cout << k << sp;
            chk=1;
            return;
        }
    }else{
        forr(i,1,n+1){
            if(visited[i])continue;
            visited[i]=true;
            vec.push_back(i);
            sSearch();
            visited[i]=false;
            vec.pop_back();
        }
    }
}

int main() {macos;

    cin >> n >> k >> l;
    sSearch();

    return 0;
}