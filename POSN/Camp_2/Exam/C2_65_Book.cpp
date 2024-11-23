#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
bool chk[36];
string in,s="";
vector<char> vec;
bool vis[51];
int cnt=0;
//combination
void sSearch(int i){
    //for(char c:vec)cout << c << ' ';cout << endll;
    cnt++;
    if(vec.size()==s.size())return;
    for(int j=i+1; j<s.size(); j++){
        if(vis[j])continue;
        if(i!=-1&&vec.back()-s[j]==-1)continue;
        vis[j]=true;
        vec.push_back(s[j]);
        sSearch(j);
        vec.pop_back();
        vis[j]=false;
    }
}

int main(){macos;

    cin >> in;
    forr(i,0,in.size()){
        if('0'<=in[i]&&in[i]<='9')chk[in[i]-'0']=true;
        else chk[in[i]-'A'+10]=true;
    }
    forr(i,0,37){
        if(chk[i]){
            if(i<=9)s+='0'+i;
            else s+='A'+i-10;
        }
    }
    sSearch(-1);
    cout << cnt-1;

    return 0;
}