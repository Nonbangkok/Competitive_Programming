#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
const int N=5002;
struct Non{int a,b,w;};
vector<Non> mangos;
int qs[N][N];
int main(){macos;

    int N,M,R,C;
    cin >> N >> M >> R >> C;
    forr(i,0,N){
        int x,y,w;cin >> x >> y >> w;
        mangos.push_back({x,y,w});
    }

    forr(i,0,M){
        int x,y;cin >> x >> y;
        qs[x][y]++;
    }

    forr(i,1,R+1)forr(j,1,C+1)qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];

    int l=1,r=max(R,C),mid;
    while(l<r){
        mid=(l+r)>>1;
        

        bool chk=1;
        for(auto [x,y,w]:mangos){
            int x1=max(0,x-mid-1),y1=max(0,y-mid-1);
            int x2=min(R,x+mid),y2=min(C,y+mid);
            if(qs[x2][y2]-qs[x2][y1]-qs[x1][y2]+qs[x1][y1]<w){
                chk=0;
                break;
            }
        }

        if(chk)r=mid;
        else l=mid+1;
    }
    cout << l;

    return 0;
}