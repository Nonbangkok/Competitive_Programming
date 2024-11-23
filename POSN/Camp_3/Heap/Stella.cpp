#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (long long i = a; i < n; i++)
#define forl(i, a, n) for (long long i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    ll mana,start,time,type;

    bool operator < (const Non &rhs)const{
        if(mana!=rhs.mana)return mana<rhs.mana;
        return start>rhs.start;
    }
};

priority_queue<Non> q;

int main(){macos;

    ll n,a,b,cnt=0,ans=0,sz=0;
    char ch;
    cin >> n;

    forr(i,1,n+1){
        cin >> ch;
        if(ch=='c'){
            cin >> ch;
            if(ch=='n'){
                cin >> a;
                q.push({a,i,1,0});
            }else{
                cin >> a >> b;
                q.push({a,i,b,1});
            }
        }else{
            while(!q.empty()){
                auto [ma,st,t,ty]=q.top();
                q.pop();
                cnt=(i-st)/t;
                if(!ty||!cnt){ans+=ma;break;}
                //ma>>=cnt;
                forr(j,0,cnt)ma>>=1;
                if(ma)q.push({ma,st+(t*cnt),t,ty});
            }
        }
    }
    while(!q.empty()){
        auto [ma,st,t,ty]=q.top();
        q.pop();
        cnt=(n-st)/t;
        //ma>>=cnt;
        forr(j,0,cnt)ma>>=1;
        if(!ty||ma)sz++;
    }
    cout << ans << endll << sz;

    return 0;
}