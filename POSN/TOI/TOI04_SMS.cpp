#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
string mp[3][3]={{{"DEL"},{"ABC"},{"DEF"}},{{"GHI"},{"JKL"},{"MNO"}},{{"PQRS"},{"TUV"},{"WXYZ"}}};
int main(){macos;

    vector<char> s;
    int i,j,m,n,x,y,pos,cnt;
    cin >> m;
    forr(k,0,m){
        if(!k){
            cin >> pos >> n;
            cnt=1;
            forr(a,0,3)forr(b,0,3){
                if(cnt==pos){
                    i=a;j=b;
                    a=3;b=3;
                }
                cnt++;
            }
        }else{
            cin >> x >> y >> n;
            i+=y;j+=x;
        }
        if(i!=0||j!=0)s.push_back(mp[i][j][(n-1)%mp[i][j].size()]);
        else while(n--)if(!s.empty())s.pop_back();
    }
    if(s.empty())cout << "null";
    else for(auto l:s)cout << l;

    return 0;
}