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
    int mp,no,hl;

    bool operator < (const Non &rhs)const{
        if(mp!=rhs.mp)return mp>rhs.mp;
        return no<rhs.no;
    }
};

int main() {macos;

    int n,a,b,ans=0;
    cin >> n;
    char ch;
    priority_queue<Non> pq;

    forr(i,1,n+1){
        cin >> ch;
        if(ch=='c'){
            cin >> ch;
            if(ch=='n'){
                cin >> a;
                pq.push({a,i,-1});
            }else{
                cin >> a >> b;
                pq.push({a,i,b});
            }
        }else if(!pq.empty()){
            if(pq.top().hl==-1){
                ans+=pq.top().mp;
                pq.pop();
            }else{
                int temp=pq.top().mp;
                cout << temp << sp << i << sp << pq.top().no << sp << b << sp << (i-pq.top().no)/b << endll;
                forr(j,0,(i-pq.top().no+1)/b)temp/=2;
                ans+=temp;
                pq.pop();
            }
        }
    }
    cout << ans << sp << pq.size();

    //not finished

    return 0;
}