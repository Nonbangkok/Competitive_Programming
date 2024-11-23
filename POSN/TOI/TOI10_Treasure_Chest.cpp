#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Non{
    ll pos,type,num;

    bool operator < (const Non &rhs)const{
        if(pos!=rhs.pos)return pos<rhs.pos;
        else return type<rhs.type;
    }
};

int s[4];//2 3 5 7

int main() {macos;

    vector<Non> A;
    ll m,n;
    cin >> m >> n;
    forr(i,0,m){
        ll x,l,r;
        cin >> x >> l >> r;
        A.push_back({l,1,x});
        A.push_back({r,2,x});
    }
    sort(A.begin(),A.end());
    cout << endll;
    ll mx=-1,start=-2,cnt=0;
    for(auto i : A){
        if(i.type==1){
            ll k=i.num;
            if(k==2)s[0]++;
            if(k==3)s[1]++;
            if(k==4)s[0]+=2;
            if(k==5)s[2]++;
            if(k==6)s[0]++,s[1]++;
            if(k==7)s[3]++;
            if(k==8)s[0]+=3;
            if(k==9)s[1]+=2;
            if(k==10)s[0]++,s[2]++;
            start=i.pos;
        }else{
            ll k=i.num,temp=1;
            for(auto j : s) temp*=(j+1);
            if(temp==mx)cnt+=i.pos-start+1;
            if(temp>mx){
                cnt=i.pos-start+1;
                mx=temp;
            }
            if(k==2)s[0]--;
            if(k==3)s[1]--;
            if(k==4)s[0]-=2;
            if(k==5)s[2]--;
            if(k==6)s[0]--,s[1]--;
            if(k==7)s[3]--;
            if(k==8)s[0]-=3;
            if(k==9)s[1]-=2;
            if(k==10)s[0]--,s[2]--;
        }
    }
    cout << mx << sp << cnt;

    return 0;
}