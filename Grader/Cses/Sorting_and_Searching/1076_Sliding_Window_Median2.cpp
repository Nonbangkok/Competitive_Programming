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
int n,k;
int a[N];
vector<int> coor;

struct Fenwick{
    int fw[N];

    Fenwick(){
        forr(i,0,N)fw[i] = 0;
    }

    void update(int idx, int val){
        for(int i=idx;i<=coor.size();i+=i&-i)fw[i] += val;
    }

    int query(int idx){
        int sum = 0;
        for(int i=idx;i>0;i-=i&-i)sum += fw[i];
        return sum;
    }
}fw;

int main(){macos;

    cin >> n >> k;
    forr(i,1,n+1)cin >> a[i],coor.push_back(a[i]);

    sort(coor.begin(),coor.end());
    coor.erase(unique(coor.begin(),coor.end()),coor.end());

    forr(i,1,n+1){
        fw.update(lower_bound(coor.begin(),coor.end(),a[i])-coor.begin()+1,1);
        if(i>=k+1)fw.update(lower_bound(coor.begin(),coor.end(),a[i-k])-coor.begin()+1,-1);
        if(i>=k){
            int l = 0, r = coor.size() + 1, m;
            while(l<r){
                m = (l+r) >> 1;
                if(fw.query(m)>=(k+1)/2&&fw.query(m-1)<(k+1)/2)break;
                else if(fw.query(m-1)<(k+1)/2)l = m + 1;
                else r = m;
            }
            cout << coor[m-1] << sp;
        }
    }

    return 0;
}